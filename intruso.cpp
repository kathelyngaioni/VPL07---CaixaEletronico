#include "intruso.hpp"
#include <sstream>
#include <vector>
#define TAMSENHA 16

void Intruso::set_senha_vazada(std::string vazou){
	std::string _vazou;
	for(int s=0;s<vazou.size();s++){
		if(vazou[s]!=' ') _vazou += vazou[s];
	}
	entradas.insert(_vazou);
}
std::string Intruso::crack_senha(){
 int n=2*(entradas.size());
 std::string sequencia;
 std::set<std::string>nova_sequencia;
 std::vector<char> a; 
 std::string senha_vazada;
 int cont[n];

//reorganizando a sequencia da senha vazada
 std::set<std::string>::iterator it;
 for(it=entradas.begin();it!=entradas.end();it++){
   for(int i=0;i<TAMSENHA;i++)	{
	if((*it)[i]=='A'){a.push_back((*it)[0]);a.push_back((*it)[1]);}
    if((*it)[i]=='B'){a.push_back((*it)[2]);a.push_back((*it)[3]);}
	if((*it)[i]=='C'){a.push_back((*it)[4]);a.push_back((*it)[5]);}
	if((*it)[i]=='D'){a.push_back((*it)[6]);a.push_back((*it)[7]);}
	if((*it)[i]=='E'){a.push_back((*it)[8]);a.push_back((*it)[9]);}
	}
	for(int j=0;j<a.size();j++)sequencia+=a[j];
	nova_sequencia.insert(sequencia);
	a.clear();
	sequencia.clear();
 }
 //reorganizando novamente
 std::vector<std::string>new_sequencia;
 for(int k=0;k<6;k++){
	std::set<std::string>::iterator it;
	  for(it=nova_sequencia.begin();it!=nova_sequencia.end();it++){
			a.push_back((*it)[2*k]);
		    a.push_back((*it)[2*k+1]);
		  }
		for(int u=0;u<a.size();u++)
		sequencia += a[u];
		new_sequencia.push_back(sequencia);
	    a.clear();
		sequencia.clear();
		}
 //comparando as new_sequencias e inicializando com 0 o contador
	    for(int m=0;m<n;m++)cont[m]=0;
	
	    for(int z=0;z<new_sequencia.size();z++){
		sequencia = new_sequencia[z];
		for(int w=0;w<n;w++){
          for(int l=0;l<n;l++){
			if(sequencia[w]==sequencia[l])
				cont[w]++;  
             }
			}
			for(int v=0;v<sequencia.size();v++){
			  if(cont[v]==entradas.size()){
			    a.push_back(sequencia[v]);
			   break;
			  }
		    }
		sequencia.clear();
		for(int m=0;m<n;m++)cont[m]=0;
		}
	     for(int f=0;f<6;f++){senha_vazada+=a[f];senha_vazada+= " ";}
	    return senha_vazada;	 
}