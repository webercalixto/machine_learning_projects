/** Source from https://www.learnopencv.com/deep-learning-based-text-recognition-ocr-using-tesseract-and-opencv/?ck_subscriber_id=487426114**/
#include "../01-ocr_simple/global.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	(void)argc;
    string outText;
    string imPath = argv[1];

    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

    ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    SAVE_LOG("Lendo imagem %s", imPath.c_str());

    Mat im = cv::imread(imPath, IMREAD_COLOR);
    SAVE_LOG("IMAGEM TEM TAMANHO %d X %d ",im.cols,im.rows);

    ocr->SetImage(im.data, im.cols, im.rows, 3, im.step);
    SAVE_LOG("ocr->SetImage ");

    outText = string(ocr->GetUTF8Text());

    SAVE_LOG("%s",outText.c_str());
    ocr->End();
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", im );
    waitKey(0);

    return EXIT_SUCCESS;
}
