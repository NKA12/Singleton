#ifndef __MDSINGLETON_H__
#define __MDSINGLETON_H__

#include <boost/thread/mutex.hpp>


template<typename T>
class MDSingleton
{
    private:
        virtual ~MDSingleton();
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
    protected:

    private:
        MDSingleton();
        MDSingleton(const MDSingleton& other);
        MDSingleton& operator=(const MDSingleton& other);
        static T * mInstance;
        boost::mutex mMutex;
};
template<typename T>
T * MDSingleton<T>::mInstance=0;

#endif // __MDSINGLETON_H__
