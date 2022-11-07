# VPL07---CaixaEletronico

O arquivo main.cpp já estava pronto e não era para ser modificado. Porém, a função std::cin.ignore() dentro do for fazia com que as entradas a serem testadas não "entrarem" corretamente.

No arquivo intruso.hpp, foi criado um set de strings para armazenar as entradas (senhas) do programa.

A primeira ideia para a criação do arquivo intruso.cpp é armazenar as entradas no set entradas. Pecorrer cada entrada do set e separar os números das letras. A partir disso, é criada uma nova_associacao. 