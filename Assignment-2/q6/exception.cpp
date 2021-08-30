#include <jni.h>
#include "exception.h"
#include <iostream>
#include <cstdlib>
using namespace std;

JNIEXPORT void JNICALL
Java_exception_NativeExceptionThrow(JNIEnv *env, jobject obj)
{
    jclass cls = (env)->GetObjectClass(obj);
    jmethodID mid1 = env->GetMethodID(cls, "divideMethod", "()V");
    jmethodID mid2 = env->GetMethodID(cls, "nullMethod", "()V");

    srand((unsigned int)time(NULL));
    int randomChoice=rand()%2;//generate random number 1 or 0

    //to randomly call either divide by 0 method or access null pointer method
    if (randomChoice==1){ //if choice is 1 call function which divides by 0
            env->CallVoidMethod(obj, mid1);
            jthrowable exc = (env)->ExceptionOccurred();
            if (exc) {
                jclass excClass = (env)->FindClass("java/lang/ArithmeticException");
                (env)->ThrowNew(excClass, "Divide by zero thrown from C++ code");
            }  
    }else{//call function which accesses null pointer
            env->CallVoidMethod(obj, mid2);
            jthrowable exc = (env)->ExceptionOccurred();
            if (exc) {
                jclass excClass = (env)->FindClass("java/lang/NullPointerException");
                (env)->ThrowNew(excClass, "Null Pointer Exception thrown from C++ code");
            }
    }
}