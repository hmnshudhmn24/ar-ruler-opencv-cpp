#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>

using namespace cv;
using namespace std;

const float MARKER_SIZE = 0.05f; // 5 cm marker

void detectArucoMarkers(Mat &frame, Ptr<aruco::Dictionary> &dictionary, Ptr<aruco::DetectorParameters> &parameters) {
    vector<int> markerIds;
    vector<vector<Point2f>> markerCorners;
    
    aruco::detectMarkers(frame, dictionary, markerCorners, markerIds, parameters);

    if (!markerIds.empty()) {
        aruco::drawDetectedMarkers(frame, markerCorners, markerIds);

        if (markerCorners.size() >= 2) {
            Point2f p1 = markerCorners[0][0];
            Point2f p2 = markerCorners[1][0];

            float pixelDistance = norm(p1 - p2);
            float realDistance = (pixelDistance / 200.0f) * MARKER_SIZE;

            putText(frame, "Distance: " + to_string(realDistance) + " cm", Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
        }
    }
}

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open webcam!" << endl;
        return -1;
    }

    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_4X4_50);
    Ptr<aruco::DetectorParameters> parameters = aruco::DetectorParameters::create();

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        detectArucoMarkers(frame, dictionary, parameters);
        imshow("AR Ruler", frame);

        if (waitKey(1) == 27) break; // Exit on ESC key
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
