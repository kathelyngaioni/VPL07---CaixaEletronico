#include "intruso.hpp"
#include <sstream>
#include <vector>
#define TAMSENHA 16

void Intruso::set_senha_vazada(std::string vazou){
  entradas.insert(vazou);
}
std::string Intruso::crack_senha(){
 
 std::string sequencia;
 int n = 2 * entradas.size();
 std::set<std::string>nova_sequencia;
 std::vector<char> a;
 std::string senha_vazada;
 int cont[n];
  
//reorganizando a sequencia da senha vazada
 std::set<std::string>::iterator it;
 for(it=entradas.begin();it!=entradas.end();it++){
   for(int i=0;i<TAMSENHA;i++){
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
 //comparando as new_sequencias

for(int z=0;z<new_sequencia.size();z++){
  sequencia = new_sequencia[z];
  for(int w=0;w<6;w++){
    for(int l=0;l<6;l++){
      if(sequencia[w]==sequencia[l])
        cont[w]++;  
    }
    if(cont[w]==entradas.size()){
      a.push_back(sequencia[w]);
      break;
     }
    }
  sequencia.clear();
  //zerando o contador
  for(int m=0;m<n;m++)cont[m]=0;
}
for(int f=0;f<6;f++)
  senha_vazada+=a[f];

  return senha_vazada;
}