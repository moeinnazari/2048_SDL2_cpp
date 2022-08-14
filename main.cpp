#include "App.h"

int main(int argc,char* argv[])
{
    srand(time(NULL));
    App* app=new App();
    if(!app->init())
    {
        std::cout<<"cant init app\n";
        return -1;
    }
    else
    {
        if(!app->loadFile())
        {
            std::cout<<"cant load file\n";
            return -1;
        }
        else
        {
           app->run();


        }
    }
    app->clean();
    delete app;
    return 0;
}

