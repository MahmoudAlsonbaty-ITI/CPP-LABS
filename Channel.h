#ifndef CHANNEL_H
#define CHANNEL_H
 
class Channel
{
private:
    int* data;
    int readIndex;
    int writeIndex;
 
public:
    Channel();
    ~Channel();
 
    void write(int data);
    int read();
};
 
#endif
 