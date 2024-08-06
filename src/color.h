#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

struct HLSA {
    int h; // Ton: 0 - 360
    int l; // parlaklık: 0 - 100
    int s; // doygunluk: 0 - 100
    double a; // Alfa: 0 - 1
};

struct RGBA {
    int r;
    int g;
    int b;
    int a; // Alfa: 0 - 1
};

char* rgbaToHex(RGBA rgba) {
    char hexColor[8];
    std::snprintf(hexColor, sizeof(hexColor), "#%02x%02x%02x%02x", rgba.r, rgba.g, rgba.b, rgba.a);
    return (hexColor);
}

HLSA rgbaToHlsa(RGBA rgba) {
    double red = rgba.r / 255.0;
    double green = rgba.g / 255.0;
    double blue = rgba.b / 255.0;
    double alpha = rgba.a / 100;

    double maxVal = std::max({red, green, blue});
    double minVal = std::min({red, green, blue});
    double delta = maxVal - minVal;

    int h = 0.0, l = (maxVal + minVal) / 2.0, s = 0.0;

    // parlaklık hesaplama
    if (delta != 0) {
        if (maxVal == red) {
            h = 60.0 * fmod(((green - blue) / delta), 6.0);
        } else if (maxVal == green) {
            h = 60.0 * (((blue - red) / delta) + 2.0);
        } else if (maxVal == blue) {
            h = 60.0 * (((red - green) / delta) + 4.0);
        }

        // doygunluk hesaplama
        if (l != 0) {
            s = delta / (1.0 - fabs(2.0 * l - 1.0));
        }
    }

    if (h < 0.0) {
        h += 360.0;
    }

    return {h, l, s, alpha};
}


