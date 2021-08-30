#include <jni.h>
#include "palindrome.h"
#include <iostream>
#include <string.h>
using namespace std;

JNIEXPORT jboolean JNICALL
Java_palindrome_checkpalindrome(JNIEnv *env, jobject obj, jstring str)
{
    const char *s = env->GetStringUTFChars(str,0);
    int len = env->GetStringUTFLength(str);
    jboolean ans = true;
    int i=0,j = len-1;
    while(i<j){
        if(s[i]!=s[j]){
            ans = false;
            break;
        }
        i++;
        j--;
    }
    return ans;
}