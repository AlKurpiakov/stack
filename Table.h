#pragma once
#include <iostream>
#include <iomanip>
#include <optional>
using namespace std;

template<typename T1, typename T2>
class Table{
private:
    string _title_col1;
    string _title_col2;
    size_t _table_size;
    optional<T1>* _col1;
    optional<T2>* _col2;
    size_t _count;
public:
    Table(string s1, string s2,size_t size){
        _title_col1=s1;
        _title_col2=s2;
        _table_size=size;
        _col1=new optional<T1>[_table_size];
        _col2=new optional<T2>[_table_size];
        _count =0;

    }
    void AppendRow(optional<T1> elem1, optional<T2> elem2){
        _col1[_count]=elem1;
        _col2[_count]=elem2;
        _count++;

    }

    T2 GetElemFromCol2(size_t str){
        return _col2[str];
    }

    T1 GetElemFromCol1(size_t str){
        return _col1[str];
    }
    void Print(){
        os<<"|"<<setw(5)<<t._title_col1<<" | "<<setw(5)<<t._title_col2<<"|"<<endl;
        for (size_t i=0;i<15;i++){
            cout<<"-";
        }
        cout<<endl;
        
        for(size_t i=0; i<t._count;i++){
            if(t._col1[i]==nullopt){
                os<<setw(5)<<"no";
            }
            else
            os<<setw(5)<<t._col1[i].value();
            os<<"|";
            if(t._col2[i]==nullopt){
                os<<setw(5)<<"no";
            }
            else
            os<<setw(5)<<t._col2[i].value();
            cout<<endl;

        }
         for (size_t i=0;i<15;i++){
            cout<<"-";
        }
        return os;
    }

};