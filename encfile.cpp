#include <bits/stdc++.h>
#include "SHA256.h"
using namespace std;

char *assign(char *a, string &b){
    for(int i=0; i<b.size(); ++i)a[i]=b[i];
    a[b.size()]='\0';
    return a;
}

signed main(){
    char name[100], oname[104];
    string Name, Oname, cmd;
    cin>>cmd, getline(cin, Name);
    if(cmd!="enc"&&cmd!="dec")cout<<cmd<<": command not found\n", exit(0);
    for(int i=0; i<Name.size()-1; ++i)Name[i]=Name[i+1]; Name.pop_back();
    Oname=Name+"."+cmd;
    assign(name, Name), assign(oname, Oname);
    cout<<"input file: "<<name<<endl;
    cout<<cmd<<"ode file: "<<oname<<endl;
    FILE *in=fopen(name, "rb"), *out=fopen(oname, "wb");
    char c, c0=0;
    long long cnt=0;
    if(cmd=="enc")while(fread(&c, 1, 1, in)){
        c0^=c, fwrite(&c0, 1, 1, out);
        if(++cnt%100000000==0)cout<<cnt<<" bits written\n";
    }
    else while(fread(&c, 1, 1, in)){
        char d=c^c0;
        fwrite(&d, 1, 1, out), c0=c;
        if(++cnt%100000000==0)cout<<cnt<<" bits written\n";
    }
    cout<<"done\n";
}
