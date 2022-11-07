#include "intruso.hpp"
#include <sstream>
#include <vector>

void Intruso::set_senha_vazada(std::string vazou){
entradas.insert(vazou);
}
std::string Intruso::crack_senha(){

int associcao_caixa;
std::string nova_associacao;
std::string letras;
std::istringstream stream_string;
std::vector<std::string>sequencias;

//percorrer o set e pegar a parte da associacao do caixa
for(std::string _senha : entradas){
stream_string = std::istringstream(_senha);
stream_string >> associcao_caixa;
stream_string >> letras;
std::string associacao = std::to_string(associcao_caixa);
 
for(int i=0;i<letras.size();i++){
 if(letras[i]=='A') nova_associacao += associacao[0] + associacao[1];
 if(letras[i]=='B') nova_associacao += associacao[2] + associacao[3];
 if(letras[i]=='C') nova_associacao += associacao[4] + associacao[5];
 if(letras[i]=='D') nova_associacao += associacao[6] + associacao[7];
 if(letras[i]=='E') nova_associacao += associacao[8] + associacao[9];    
 } 
}
sequencias.push_back(nova_associacao);
std::string senha;
std::vector<std::string>::iterator it;
for(it=sequencias.begin();it!=sequencias.end();it++){
  for(int k=0;k<12;k++){
   if((*it)[2*k]==(*it++)[2*k])
    senha += (*it)[2*k];
     if((*it)[2*k]==(*it)[2*k+1])
       senha += (*it)[2*k];
     if((*it)[2*k+1]==(*it++)[2*k])
     senha += (*it)[2*k];
    if((*it)[2*k+1]==(*it)[2*k+1])
     senha += (*it)[2*k];
}
return senha;
}