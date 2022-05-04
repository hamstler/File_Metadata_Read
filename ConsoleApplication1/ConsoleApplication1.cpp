#pragma pack(1)
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "bmp.h"

vector<char> buffer;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

void fill() {
    std::ifstream file("test.bmp");

    if (file) {
        file.seekg(0, std::ios::end);
        streampos length = file.tellg();
        file.seekg(0, std::ios::beg);

        buffer.resize(length);
        file.read(&buffer[0], length);

        file_header = (PBITMAPFILEHEADER)(&buffer[0]);
        info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));
    }
}

int main() {
    fill();

    cout << "Type of file: " << file_header->bfType << endl;
    cout << "Size of file in bytes: " << file_header->bfSize << endl;
    cout << "Reserved1: " << file_header->bfReserved1 << endl;
    cout << "Reserved2: " << file_header->bfReserved2 << endl;
    cout << "OffBits: " << file_header->bfOffBits << endl;

    cout << "Size of heading:" << info_header->biSize << endl;
    cout << "Resolution of file (Width/Height): " << info_header->biWidth << "px " << " " << info_header->biHeight << "px " << endl;
    cout << "Color planes:" << info_header->biPlanes << endl;
    cout << "Bits per pixel:" << info_header->biBitCount << endl;
    cout << "Compression:" << info_header->biCompression << endl;
    cout << "Size of image:" << info_header->biSizeImage << endl;
    cout << "Vertical resolution:" << info_header->biXPelsPerMeter << endl;
    cout << "Horizontal resolution :" << info_header->biYPelsPerMeter << endl;
    cout << "Color palette count:" << info_header->biClrUsed << endl;
    cout << "Important colors in palette:" << info_header->biClrImportant << endl;

    return 0;
}