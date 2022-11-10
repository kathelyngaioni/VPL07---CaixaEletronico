# VPL07---CaixaEletronico

O arquivo main.cpp já estava pronto e não era para ser modificado. Porém, a função std::cin.ignore() dentro do for fazia com que as entradas a serem testadas não "entrarem" corretamente.

No arquivo intruso.hpp, foi criado um set de strings para armazenar as entradas (senhas) do programa. 
 
As entradas do programa (senha) possuem espaçamento. Assim, no método void set_senha_vazada(std::string vazou) "tira" os espaçamentos das entradas.

void Intruso::set_senha_vazada(std::string vazou){
	std::string _vazou;
	for(int s=0;s<vazou.size();s++){
		if(vazou[s]!=' ') _vazou += vazou[s];
	}
	entradas.insert(_vazou);
}

A lógica utilizada no VPL foi a seguinte: é criada a primeira sequencia a partir de uma entrada, por exemplo, a entrada 1739085624BCEAEB possui a logica do caixa eletronico e a senha digitada pelo usuario. A logica do caixa eletronico é 1739085624 ; 17 corresponde a A, 39 corresponde a B, 08 corresponde a C, 56 corresponde a D e 24 a E. A partir da senha digitada pelo usuario, eu crio minha primeira sequencia que será : BCEAEB = 390824172439.
Outro exemplo, a entrada 9075846231ECCBDA vai gerar a sequencia 318484756290. Para gerar primeira sequencia é utilizado a seguinte parte do código:

  std::string sequencia;
  std::set<std::string>nova_sequencia;
  std::vector<char> a;

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
O set de strings nova_sequencia vai armazenas as sequencias que foram criadas.



Depois de criada a nova_sequencia vamos criar a segunda sequencia chamada new sequencia. Para a criação, usamos os 2 primeiros caracteres de uma sequencia com os 2 primeiros caracteres de outra sequencia e a armazenamos em no vetor std::vector<std::string>new_sequencia. Depois usamos a 3ª e a 4ª das sequencias e assim sucessivamente. Por exemplo, considere as duas sequencias : 390824172439 e 318484756290. A partir dessa duas sequencias serão criadas as sequencias: 3931,0884,2484,1775,2462 e 3990.

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

A última parte do programa utiliza um contador para contar quantas vezes o mesmo numero aparece na sequencia. Se o numero aparece o mesmo número de vezes que a quantidade de entradas (entradas.size()), então esse é o número da senha. Por exemplo, a sequencia 3931 tem o contador {2,1,2,1} e o número da senha é 3; já que eu utilizei duas entradas para gerar essa sequencia. 
0884 = {1,2,2,1}
2484 = {1,2,1,2}
1775 = {1,2,2,1}

O codigo correspondente a essa lógica:
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