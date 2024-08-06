#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

struct HLSA {
    double h; // Ton: 0 - 360
    double l; // parlaklık: 0 - 1
    double s; // doygunluk: 0 - 1
    double a; // Alfa: 0 - 1
};

rgbaToHex(int r, int g, int b, int a = 255) {
    char hexColor[8];
    std::snprintf(hexColor, sizeof(hexColor), "#%02x%02x%02x%02x", r, g, b, a);
    return (hexColor);
}

HLSA rgbaToHlsa(int r, int g, int b, int a = 255) {
    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;
    double alpha = a / 255.0;

    double maxVal = std::max({red, green, blue});
    double minVal = std::min({red, green, blue});
    double delta = maxVal - minVal;

    double h = 0.0, l = (maxVal + minVal) / 2.0, s = 0.0;

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


