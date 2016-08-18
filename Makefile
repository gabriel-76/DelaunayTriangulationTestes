main : compile

compile :	install-pre-requisites
	./compile.sh

install-pre-requisites :
	./install-pre-requisites.sh

clean :
	./clean.sh
