#include <jni.h>
#include "sortarray.h"
#include <iostream>
using namespace std;

JNIEXPORT jintArray JNICALL
Java_sortarray_displaysortarray(JNIEnv *env, jobject obj, jintArray array)
{
    jsize n = (env)->GetArrayLength(array);
    jint* arr = (env)->GetIntArrayElements(array, NULL);
    jintArray result = (env)->NewIntArray(n);
    int i, j, temp;
    for (i=0; i<n-1; i++)    
        for (j=0; j<n-i-1; j++)
            if (arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
    env->SetIntArrayRegion(result,0,n,arr);
  return result;
}