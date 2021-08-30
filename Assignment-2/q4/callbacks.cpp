#include <jni.h>
#include "callbacks.h"
#include <iostream>
using namespace std;

JNIEXPORT void JNICALL 
Java_callbacks_nativeMethod(JNIEnv *env, jobject obj)
{
    jclass cls = env->GetObjectClass(obj);
    jmethodID sid = env->GetStaticMethodID(cls, "staticMethod", "()V");
    jmethodID nid = env->GetMethodID(cls, "objectMethod", "()V");
    env->CallStaticVoidMethod(cls, sid);
    env->CallVoidMethod(obj, nid);
}