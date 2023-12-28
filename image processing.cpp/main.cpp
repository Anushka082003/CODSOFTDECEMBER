
#include <iostream>
#include <vector>
#include <algorithm>

// Image class representing a simplified image
class Image {
private:
    int width;
    int height;
    std::vector<std::vector<int>> pixels; // Simplified representation of pixel values

public:
    Image(int w, int h) : width(w), height(h), pixels(w, std::vector<int>(h, 0)) {}

    // Display the image (simplified representation)
    void display() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << pixels[j][i] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Set pixel value at coordinates (x, y)
    void setPixel(int x, int y, int value) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[x][y] = value;
        }
    }

    // Apply grayscale filter
    void applyGrayscale() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int average = (pixels[j][i] + pixels[j][i] + pixels[j][i]) / 3;
                pixels[j][i] = average;
            }
        }
    }

    // Apply blur filter
    void applyBlur() {
        // Simplified blur operation: each pixel takes the average of its neighbors
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < width - 1; ++j) {
                int average = (pixels[j - 1][i - 1] + pixels[j][i - 1] + pixels[j + 1][i - 1] +
                               pixels[j - 1][i] + pixels[j][i] + pixels[j + 1][i] +
                               pixels[j - 1][i + 1] + pixels[j][i + 1] + pixels[j + 1][i + 1]) / 9;
                pixels[j][i] = average;
            }
        }
    }

    // Apply sharpen filter
    void applySharpen() {
        // Simplified sharpen operation: each pixel is updated based on its neighbors
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < width - 1; ++j) {
                int sharpness = 9 * pixels[j][i] - pixels[j - 1][i - 1] - pixels[j][i - 1] - pixels[j + 1][i - 1] -
                                pixels[j - 1][i] - pixels[j][i] - pixels[j + 1][i] -
                                pixels[j - 1][i + 1] - pixels[j][i + 1] - pixels[j + 1][i + 1];
                pixels[j][i] = std::max(0, std::min(sharpness, 255));
            }
        }
    }
};

int main() {
    // Create an image (100x50 pixels)
    Image myImage(100, 50);

    // Load an image (simplified pixel values)
    // For simplicity, assume the image has grayscale pixel values ranging from 0 to 255
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            myImage.setPixel(j, i, i * 5);  // Simple gradient
        }
    }

    // Display the original image
    std::cout << "Original Image:\n";
    myImage.display();

    // Apply grayscale filter
    myImage.applyGrayscale();
    std::cout << "\nImage After Grayscale Filter:\n";
    myImage.display();

    // Apply blur filter
    myImage.applyBlur();
    std::cout << "\nImage After Blur Filter:\n";
    myImage.display();

    // Apply sharpen filter
    myImage.applySharpen();
    std::cout << "\nImage After Sharpen Filter:\n";
    myImage.display();

    return 0;
}
