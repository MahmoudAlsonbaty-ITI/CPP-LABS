#include <iostream>
#include <memory>

using namespace std;

class IFeed {
public:
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual ~IFeed() {}
};

class LiDAR : public IFeed {
public:
    void activate() override   { cout << "LiDAR activated" << endl; }
    void deactivate() override { cout << "LiDAR deactivated" << endl; }
    void scanEnv()             { cout << "LiDAR scanning environment" << endl; }
};

class Camera : public IFeed {
public:
    void activate() override   { cout << "Camera activated" << endl; }
    void deactivate() override { cout << "Camera deactivated" << endl; }
    void playFeed()            { cout << "Camera playing feed" << endl; }
};

class Mic : public IFeed {
public:
    void activate() override   { cout << "Mic activated" << endl; }
    void deactivate() override { cout << "Mic deactivated" << endl; }
    void playSound()           { cout << "Mic playing sound" << endl; }
};

class DroneControlStation {
private:
    unique_ptr<IFeed> ptr;

public:
    void registerFeed(unique_ptr<IFeed> feed) {
        ptr = move(feed);
        cout << "Feed registered" << endl;
    }

    void activateFeed() {
        if (ptr) ptr->activate();
    }

    void deactivateFeed() {
        if (ptr) ptr->deactivate();
    }

    void viewFeed() {
        if (!ptr) {
            cout << "No feed registered" << endl;
            return;
        }

        LiDAR* lidar = dynamic_cast<LiDAR*>(ptr.get());
        if (lidar) {
            lidar->scanEnv();
            return;
        }

        Camera* camera = dynamic_cast<Camera*>(ptr.get());
        if (camera) {
            camera->playFeed();
            return;
        }

        Mic* mic = dynamic_cast<Mic*>(ptr.get());
        if (mic) {
            mic->playSound();
            return;
        }
    }
};

int main() {
    DroneControlStation station;

    unique_ptr<IFeed> lidar = make_unique<LiDAR>();

    station.registerFeed(move(lidar));

    station.activateFeed();
    station.viewFeed();
    station.deactivateFeed();

    cout << "-----------------" << endl;

    station.registerFeed(make_unique<Camera>());

    station.activateFeed();
    station.viewFeed();
    station.deactivateFeed();

    return 0;
}