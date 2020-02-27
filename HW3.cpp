#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <iosfwd>
#include <istream>
#include <ostream>

using namespace std;

struct dept{
	int did;
	string dname;
	double budget;
	int managerid;
};

struct emp{
	int eid;
	string ename;
	int age;
	double salary;
};


dept D_pt[250];
emp E_ptr[250];
int D_pt_Size = 250,E_ptr_Size= 250;

bool Dept_Cus_Compare(dept a, dept b);
bool Emp_Cus_Compare(emp a, emp b);
int rtnidx(int idx,int num);
int rtnszep(emp str);
int rtnszdp(dept str);

int main() {
	ifstream D_file,E_file;
	ofstream Out_file,sub_Out_file;
	string Buffer,Sub_Buffer;
	int idx = 0,idx_D = 0,idx_E = 0;
	stringstream S_s;

	int Block = 22;
	int r = 0,s = 0,j = 20;
	int D_Size = rtnszdp(*D_pt),D_P_Size = rtnszdp(*D_pt);
	int R_B_Count = ((D_Size/D_P_Size)/Block) + 1;
	int E_Size = rtnszep(*E_ptr),E_P_Size = rtnszep(*E_ptr);
	int S_B_Count = ((E_Size/E_P_Size)/Block) + 1;
	struct dept R_Temp[R_B_Count];
	struct emp S_Temp[S_B_Count];
	int R_B_min,S_B_min;
	int R_Tar_Pos,S_Tar_Pos;
	D_file.open("Dept.csv", ios::in);
	E_file.open("Emp.csv", ios::in);
	Out_file.open("join.csv",ios::out);	
	int Bit_Check = -1;
	
	Bit_Check = D_file?0:-1;
	int threeck = 0;
	if(Bit_Check==-1){
		cout << "open file failed.";
		return -1;
	}else{
		threeck++;
	}
	Bit_Check = -1;
	Bit_Check = E_file?0:-1;
	if(Bit_Check==-1){
		cout << "open file failed.";
		return -1;
	}else{
		threeck++;
	}
	Bit_Check = -1;
	Bit_Check = Out_file.is_open()?0:-1;
	if(Bit_Check==-1){
		cout << "open file failed.";
		return -1;
	}else{
		threeck++;
	}

	int finish = -1;
	if(Bit_Check!=-1){
		if(threeck==3){
			do{
			idx = 0;
			getline(D_file, Buffer, '\n');
			Buffer.erase(remove(Buffer.begin(), Buffer.end(), '"'), Buffer.end());
			stringstream S_s(Buffer);
			
			while(getline(S_s, Sub_Buffer, ',')){
				idx = rtnidx(idx,4);
				switch(idx){
					case 0:
						D_pt[idx_D].did = stoi(Sub_Buffer);
						break;
					case 1:
						D_pt[idx_D].dname = Sub_Buffer;
						break;
					case 2:
						D_pt[idx_D].budget = stod(Sub_Buffer);
						break;
					case 3:
						D_pt[idx_D].managerid = stoi(Sub_Buffer);
						break;
				}
				idx = idx + 1;
	   		}
	   		idx_D =idx_D + 1;
			}while(!D_file.eof());
	
		
	   		do{
			  	idx = 0;
				getline(E_file, Buffer, '\n');
				Buffer.erase(remove(Buffer.begin(), Buffer.end(), '"'), Buffer.end());
				stringstream S_s(Buffer);
				while(getline(S_s, Sub_Buffer, ',')){
			   		idx = rtnidx(idx,4);
					switch(idx){
						case 0:
							E_ptr[idx_E].eid = stoi(Sub_Buffer);
							break;
						case 1:
							E_ptr[idx_E].ename = Sub_Buffer;
							break;
						case 2:
							E_ptr[idx_E].age = stoi(Sub_Buffer);
							break;
						case 3:
							E_ptr[idx_E].salary = stod(Sub_Buffer);
							break;
					}
					idx = idx +1;
				}
				idx_E += 1;
			}while(!E_file.eof());
			Bit_Check = -1;
			int AM_D_Size = (sizeof(D_pt)/rtnszdp(*D_pt));
			for(int i = 0 ; i<AM_D_Size; i+=Block ){
				Bit_Check = (i + Block < AM_D_Size)?0:-1;
				switch(Bit_Check){
					case 0:
						sort(D_pt + i, D_pt + i + (Block - 1),Dept_Cus_Compare);
						break;
					case -1:
						sort(D_pt + i, D_pt + AM_D_Size, Dept_Cus_Compare);
						break;
				}
			}
			
			sort(D_pt, D_pt+D_pt_Size, Dept_Cus_Compare);
		
			Bit_Check = -1;
			int AM_E_Size = (sizeof(E_ptr)/rtnszep(*E_ptr));
			for(int i = 0;i < AM_E_Size ;i+=Block){
				Bit_Check =(i + Block < AM_E_Size)?0:-1;
				switch(Bit_Check){
					case 0:
						sort(E_ptr + i, E_ptr + i + (Block - 1), Emp_Cus_Compare);
						break;
					case -1:
						sort(E_ptr + i, E_ptr + AM_E_Size, Emp_Cus_Compare);
						break;
				} 
			}
		
			sort(E_ptr, E_ptr+E_ptr_Size, Emp_Cus_Compare);
			Bit_Check = -1;
			int idcheck = -1;
			int Block_Size = Block / (R_B_Count + S_B_Count) * R_B_Count;
			for(int i=0;;i++){
				if(i > E_ptr_Size + D_pt_Size)
					break;
				for(int i = 0; i < Block_Size; i += Block){
					j = 0;
					idcheck = R_Temp[j].managerid == 00?0:-1;
					do{
						j++;	
						R_Temp[j].managerid = D_pt[i+j].managerid;
						idcheck = R_Temp[j].managerid == 00?0:-1;
					}while(idcheck==-1);
					Bit_Check = S_Temp[j].eid < S_B_min?0:-1;	
					switch(Bit_Check){
						case 0:
							R_B_min = R_Temp[i+j].managerid;
							R_Tar_Pos = i+j;
							break;
						default:
							break;
					}
				}
				Bit_Check = -1;
				for(int i = 0; i < Block_Size; i += Block){
					j = 0;
					do{
						j++;
						S_Temp[j].eid = E_ptr[i+j].eid;
						idcheck =S_Temp[i+j].eid != 00;
					}while(idcheck==-1);
					Bit_Check = S_Temp[j].eid < S_B_min?0:-1;
					switch(Bit_Check){
						case 0:
							S_B_min = S_Temp[i+j].eid;
							S_Tar_Pos = i+j;
							break;
						default:
							break;
					}
				}
			}
			int i = 0,R_p1 = 0,S_p1 = 0,check2 = -1;
			Bit_Check = -1;
			for(int i = 0;i < AM_E_Size ;i+=Block){
				Bit_Check =(i + Block < AM_E_Size)?0:-1;
				switch(Bit_Check){
					case 0:
						sort(E_ptr + i, E_ptr + i + (Block - 1), Emp_Cus_Compare);
						break;
					case -1:
						sort(E_ptr + i, E_ptr + AM_E_Size, Emp_Cus_Compare);
						break;
				} 
			}
			do{
				Bit_Check = D_pt[r].managerid > E_ptr[s].eid?1:2;
				if(Bit_Check==2){
					Bit_Check = D_pt[r].managerid == E_ptr[s].eid?3:2;
				}else{
					Bit_Check = 1;
				}
				switch(Bit_Check){
					case 1:
						s = s+1;
						break;
					case 2:
						r = r+1;
						break;
					case 3:
						check2 = D_pt[r].managerid > 0?1:-1;
						switch(check2){
							case 1:
								 Out_file << D_pt[r].did << ',' << D_pt[r].dname << ',' << D_pt[r].budget << ',' << D_pt[r].managerid 
								<< ',' << E_ptr[s].eid << ',' << E_ptr[s].ename << ',' << E_ptr[s].age << ',' << E_ptr[s].salary << endl;
								break;
							default:
								break;
						}
						r = r + 1;
						break;
				}
				i = i+1;
				
			}while(i < AM_D_Size +AM_E_Size );	
		}
		
	}
	
	
	Out_file.close();
	Bit_Check = Out_file.is_open()?0:-1;

	if(Bit_Check==0){
		cout << "fail to close the file1";
		return -1;
	}
	D_file.close();
	Bit_Check = D_file.is_open()?0:-1;

	if(Bit_Check==0){
		cout << "fail to close the file2";
		return -1;
	}
	E_file.close();
	Bit_Check = E_file.is_open()?0:-1;

	if(Bit_Check==0){
		cout << "fail to close the file3";
		return -1;
	}
	return 0;
}

bool Dept_Cus_Compare(dept a, dept b){
	int D_Value_Check = (a.managerid < b.managerid)?0:1;
	if(D_Value_Check == 0)
		return true;
	else
		return false;
};

bool Emp_Cus_Compare(emp a, emp b){
	int E_Value_Check = (a.eid < b.eid)?0:1;
    if(E_Value_Check == 0)
		return true;
	else
		return false;
};
int rtnidx(int idx,int num){
	int rtn = 0;
	rtn = idx % num;
	return rtn;
}
int rtnszdp(dept str){
	int szof = 0;
	szof = sizeof(str);
	return szof;
}
int rtnszep(emp str){
	int szof = 0;
	szof = sizeof(str);
	return szof;
}

