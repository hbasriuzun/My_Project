#include <iostream>
#include <string>
#include <cstdlib> // For system()
#include <chrono> // For std::chrono::seconds
#include <thread> // For std::this_thread::sleep_for
#include <unistd.h> // For sleep()

void openUrl(const std::string& url) {
    // Open the URL in the browser using system command
    std::string command = "open -a 'Google Chrome' " + url; // For Chrome browser
    // std::string command = "open -a 'Firefox' " + url; // For Firefox browser

    system(command.c_str());
}

void closeBrowser() {
    // Close the specific browser process for Mac
    std::string command = "pkill 'Google Chrome'"; // For Chrome browser
    // std::string command = "pkill 'Firefox'"; // For Firefox browser

    system(command.c_str());
}

int main() {
    std::string url = "https://youtu.be/ITzRr-4Oe5Q"; // URL to open
    int openCount = 30; // Number of times to open the URL
    int waitTime = 0; // Waiting time between each opening (seconds)
    int playTime = 0; // Video playback time (seconds)
    int browserWaitTime = 0; // Waiting time after opening browser (seconds)
    int totalTime = openCount * (playTime + waitTime) + openCount * browserWaitTime; // Total running time (seconds)

    for (int i = 0; i < openCount; ++i) {
        // Open the URL
        openUrl(url);
        
        // Wait for the browser to load the URL
        std::this_thread::sleep_for(std::chrono::seconds(browserWaitTime));

        // Simulate pressing the space key to start playing the video
        system("osascript -e 'tell application \"Google Chrome\" to activate'");
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for Chrome to activate
        system("osascript -e 'tell application \"System Events\" to keystroke \" \" using {control down}'"); // Press space key

        // Wait for the video playback time
        std::this_thread::sleep_for(std::chrono::seconds(playTime));

        // Wait for the specified time
        std::this_thread::sleep_for(std::chrono::seconds(waitTime));
    }

    // Wait for the total running time
    std::this_thread::sleep_for(std::chrono::seconds(totalTime));
    std::this_thread::sleep_for(std::chrono::seconds(40));
    // Close all remaining browser tabs
    closeBrowser();

    return 0;
}
