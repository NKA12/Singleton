#ifndef __TSSINGLETON_H__
#define __TSSINGLETON_H__

#include <boost/thread/mutex.hpp>


template<typename T>
class TSSingleton
{
    private:
        virtual ~TSSingleton(){kill();}

        static T & getInstance()
        {
            if(!mInstance)
            {
                boost::mutex::scoped_lock scopedLock(mMutex);
                if(!mInstance())
                        mInstance = new T();
            }
            return *mInstance ;
        }
        void kill()
        {
            if(mInstance)
            {
                delete mInstance;
                mInstance =0;
            }
        }
    protected:

    private:
        TSSingleton();
        TSSingleton(const TSSingleton& other);
        TSSingleton& operator=(const TSSingleton& other);
        static T * mInstance;
        static boost::mutex mMutex;
};
template<typename T>
T * TSSingleton<T>::mInstance=0;
template<typename T>
boost::mutex TSSingleton<T>::mMutex;
#endif // __MDSINGLETON_H__
