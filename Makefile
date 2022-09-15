all: clean pointers linkedlist

pointers:
	@echo ""
	@echo "============================="
	@echo "|       PONTEIROS           |"
	@echo "============================="
	@echo "Compilando o exemplo de ponteiros. Programa pointers."
	gcc ponteiros.c -o pointers
	chmod +x pointers
linkedlist:
	@echo ""
	@echo "============================="
	@echo "|         LISTAS            |"
	@echo "============================="
	@echo "Compilando o exemplo de lista simplesmente ligada."
	gcc log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist
	@echo "Compilando o exemplo de lista simplesmente ligada."
	gcc log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o doublylinkedlist
	chmod +x doublylinkedlist
	
clean:
	@echo ""
	@echo "============================="
	@echo "|   REMOVENDO PROGRAMAS     |"
	@echo "============================="
	@echo "Removendo todos os arquivos compilados"
	rm -f pointers pointersmatrix linkedlist doublylinkedlist