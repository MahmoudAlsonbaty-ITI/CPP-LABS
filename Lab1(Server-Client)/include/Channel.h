#ifndef CHANNEL_H
#define CHANNEL_H
 
#include <variant>
 
using ChannelData = std::variant<int, float, double>;
 
class Channel
{
public:
    virtual ~Channel();
    virtual void write(ChannelData data) = 0;
    virtual ChannelData read() = 0;
};
 
class SpeedChannel : public Channel
{
private:
    int* data;
    int readIndex;
    int writeIndex;
 
public:
    SpeedChannel();
    ~SpeedChannel() override;
    void write(ChannelData data) override;
    ChannelData read() override;
};
 
class TempChannel : public Channel
{
private:
    double* data;
    int readIndex;
    int writeIndex;
 
public:
    TempChannel();
    ~TempChannel() override;
    void write(ChannelData data) override;
    ChannelData read() override;
};
 
class RpmChannel : public Channel
{
private:
    float* data;
    int readIndex;
    int writeIndex;
 
public:
    RpmChannel();
    ~RpmChannel() override;
    void write(ChannelData data) override;
    ChannelData read() override;
};
 
#endif