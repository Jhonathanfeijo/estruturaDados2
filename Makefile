all: clear pointers linkedlist

pointers:
	@echo -e "\nCompilando o exemplo de ponteiros. Program pointers."
	gcc ponteiros.c -o pointers
	chmod +x pointers

clear:
	@echo ""
	@echo "============================================"
	@echo "|            REMOVENDO ARQUIVOS            |"
	@echo "============================================"
	@echo -e "\nEncerrando todos os arquivos compilado."
	rm -f pointers

linkedlist:
	@echo ""
	@echo "=================================================="
	@echo "|                LISTAS                          |"
	@echo "=================================================="
	@echo "Compilando o exemplo de Lista" 
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist
