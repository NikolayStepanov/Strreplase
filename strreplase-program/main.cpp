#include <iostream>

using namespace std;

size_t s_length(const char* s);
void  s_copy(char* d, const char* s, size_t n);
void  s_move(char* d, const char* s, size_t n);

void s_replace(char *pszResult, const char* pcszSubstr, const char* pcszStr2){
    const char* p2;
    size_t n_pcszSubstr, n_pcszStr2, n_pszResult;
    char* p1, *t = pszResult;

    n_pcszSubstr = s_length(pcszSubstr);
    n_pcszStr2 = s_length(pcszStr2);
    n_pszResult = s_length(pszResult);

    while(*pszResult){
        p1 = pszResult;
        p2 = pcszSubstr;
        while(*p2 && (*p2 == *p1)){
            ++p1;
            ++p2;
        }

        if(! *p2){
            if(n_pcszStr2 > n_pcszSubstr){
                s_move(pszResult + (n_pcszStr2 - n_pcszSubstr), pszResult, n_pszResult - (size_t)(pszResult - t));
                n_pszResult += n_pcszStr2 - n_pcszSubstr;
            } else {
                s_copy(pszResult, pszResult + (n_pcszSubstr - n_pcszStr2), n_pszResult - (size_t)(pszResult - t));
                n_pszResult -= n_pcszSubstr - n_pcszStr2;
            }
            s_copy(pszResult, pcszStr2, n_pcszStr2);
            pszResult  += n_pcszStr2;
            continue;
        }
        ++pszResult;
    }
}


size_t s_length(const char* s){
    const char* t = s;
    while(*s)
        ++s;
    return (size_t)(s - t);
}

void s_copy(char* d, const char* s, size_t n){
    size_t i;
    for(i = 0; i < n; ++i)
        *d++ = *s++;
}

void s_move(char* d, const char* s, size_t n){
    size_t i;
    d += (n - 1);
    s += (n - 1);
    for(i = n; i > 0; --i)
        *d-- = *s--;
}

int main()
{
    char strA[]="ABABCDCDCD--ABABCD__";
    char str_shab[]="ABCD";
    char str_zam[]="0AB";

    cout<<"Text: "<<strA<<endl;
    cout<<"Substring: "<<str_shab<<endl;
    cout<<"Replacement string: "<<str_zam<<endl;

    s_replace(strA,str_shab,str_zam);
    cout<<"Result: "<<strA<<endl;

    return 0;
}
