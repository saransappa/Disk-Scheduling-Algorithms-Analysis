#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int MAX_CYL = 0;

float fifo(vector<int> v,int l){
    int seek = 0;
    int p = l;
    string str = "";
    for(int i=0;i<v.size();i++){
        str+= to_string(p);
        str+=" -> ";
        seek += abs(v[i]-p);
        p = v[i];
    }
    str+=to_string(p);
    cout<<"FIFO disk scheduling"<<endl;
    float ans = (float)seek/v.size();
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

float sstf(vector<int> v,int l){
    int size = v.size();
    int seek = 0;
    int p = l;
    string str = "";
    while(v.size()){
        str+= to_string(p);
        if(v.size()>=1)
        str+=" -> ";
        int min = INT_MAX;
        int min_ind = -1;
        for(int i=0;i<v.size();i++){
            if(abs(v[i]-p)<min){
                min_ind = i;
                min = abs(v[i]-p);
            }
        }
        seek += min;
        p = v[min_ind];
        v.erase(v.begin()+min_ind);
    }
    str+=to_string(p);
    cout<<"SSTF disk scheduling"<<endl;
    float ans = (float)seek/size;
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

float scan(vector<int> v,int l, int dir){
    int seek = 0;
    int p = l;
    string str = "";
    sort(v.begin(),v.end());
    int s = 0;
    while(v[s]<p){
        s++;
    }
    if(dir==0){
        for(int i=s-1;i>=0;i--){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str += to_string(p)+" -> ";
        seek+= p;
        p=0;
        for(int i=s;i<INT_MAX;i++){
            str += to_string(p);
            if(i==v.size())break;
            str+=" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
    }
    else{
        for(int i=s;i<INT_MAX;i++){
            if(i==v.size())break;
            str += to_string(p);
            str+=" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str += to_string(p)+" -> ";
        seek+= abs(MAX_CYL-p);
        p = MAX_CYL;
        for(int i=s-1;i>=0;i--){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str += to_string(p);
    }
    cout<<"SCAN disk scheduling"<<endl;
    float ans = (float)seek/v.size();
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

float cscan(vector<int> v,int l, int dir){
    int seek = 0;
    int p = l;
    string str = "";
    sort(v.begin(),v.end());
    int s = 0;
    while(v[s]<p){
        s++;
    }
    if(dir == 0){
        for(int i=s-1;i>=0;i--){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str += to_string(p)+" -> ";
        seek+= p;
        p=0;
        str += to_string(p)+" -> ";
        seek+= abs(MAX_CYL-p);
        p = MAX_CYL;
        for(int i=v.size()-1;i>=s;i--){
            str += to_string(p)+" -> ";        
            if(i==v.size())break;
            seek += abs(v[i]-p);
            p = v[i];
        }
        str+=to_string(p);
    }
    else{
        for(int i=s;i<=v.size();i++){
            if(i==v.size())break;
            str += to_string(p)+" -> ";        
            seek += abs(v[i]-p);
            p = v[i];
        }
        str += to_string(p)+" -> ";
        seek+= abs(MAX_CYL-p);
        p=MAX_CYL;
        str += to_string(p)+" -> ";
        seek+= abs(p-0);
        p = 0;
        for(int i=0;i<s;i++){
            str += to_string(p)+" -> ";        
            seek += abs(v[i]-p);
            p = v[i];
        }
        str+=to_string(p);
    }
    cout<<"C-SCAN disk scheduling"<<endl;
    float ans = (float)seek/v.size();
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

float look(vector <int> v, int l, int dir){
    int seek = 0;
    int p = l;
    string str = "";
    sort(v.begin(),v.end());
    int s = 0;
    while(v[s]<p){
        s++;
    }
    if(dir==0){
        for(int i=s-1;i>=0;i--){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        for(int i=s;i<INT_MAX;i++){
            str += to_string(p);
            if(i==v.size())break;
            str+=" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
    }
    else{   
        for(int i=s;i<INT_MAX;i++){
            if(i==v.size())break;
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        for(int i=s-1;i>=0;i--){
            str += to_string(p);
            if(i!=0){
                str+=" -> ";
            }
            else{
                break;
            }
            seek += abs(v[i]-p);
            p = v[i];
        }
        str+=" -> "+to_string(v[0]);
        seek += abs(v[0]-p);
    }

    cout<<"LOOK disk scheduling"<<endl;
    float ans = (float)seek/v.size();
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

float clook(vector<int> v,int l, int dir){
    int seek = 0;
    int p = l;
    string str = "";
    sort(v.begin(),v.end());
    int s = 0;
    while(v[s]<p){
        s++;
    }
    if(dir==0){
        for(int i=s-1;i>=0;i--){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        for(int i=v.size()-1;i>=s;i--){
            str += to_string(p);
            if(i==v.size())break;
            str+=" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str+=to_string(p);
    }
    else{
        for(int i=s;i<=v.size();i++){
            if(i==v.size())break;
            str += to_string(p);
            str+=" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        for(int i=0;i<s;i++){
            str += to_string(p)+" -> ";
            seek += abs(v[i]-p);
            p = v[i];
        }
        str+=to_string(p);
    }
    cout<<"C-LOOK disk scheduling"<<endl;
    float ans = (float)seek/v.size();
    cout<<"     Disk traversal path is : "<<str<<endl;
    cout<<"     Total seek-length is : "<<seek<<endl;
    cout<<"     Average seek-length is : "<<ans<<endl;
    return ans;
}

int main(){
    cout<<"Please enter the no.of cylinders in the disk : ";
    cin>>MAX_CYL;
    MAX_CYL--;
    int l;
    cout<<"Please enter the initial head location : ";
    cin>>l;
    cout<<"Please specify the initial head direction:\n Enter 0 for left or 1 for right : ";
    int dir;
    cin>>dir;

    cout<<"Please enter the no.of disk I/O requests :  ";
    int n,k;
    cin>>n;
    vector <int> v;
    cout<<"Please enter the disk I/O requests one by one:"<<endl;
    for(int i=0;i<n;i++){
        cin>>k;
        v.pb(k);
    }
    vector <float> t;
    t.pb(fifo(v,l));
    t.pb(sstf(v,l));
    t.pb(scan(v,l,dir));
    t.pb(cscan(v,l,dir));
    t.pb(look(v,l,dir));
    t.pb(clook(v,l,dir));
    string list[6] = {"FIFO","SSTF","SCAN","C-SCAN","LOOK","C-LOOK"};
    int min=INT_MAX;
    int min_ind = -1;
    for(int i=0;i<t.size();i++){
        if(t[i]<min){
            min = t[i];
            min_ind = i;
        }
    }
    cout<<"The best disk scheduling algorithm for the given disk I/O requests is "<<list[min_ind]<<"."<<endl;
    return 0;
}