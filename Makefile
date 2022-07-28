all: clear pointers

pointers:
	@echo -e "\nCompilando o exemplo de ponteiros. Program pointers."
	gcc ponteiros.c -o pointers
	chmod +x pointers

clear:
	@echo -e "\nEncerrando todos os arquivos compilado."
	rm -f pointers