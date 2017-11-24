shell: main.c
	gcc -o shell ./main.c  ./variables/Variables.c ./parser/CommandParser.c ./parser/Utils.c ./executor/CommandExecutor.c ./executor/Utils.c ./files/FileSetup.c ./files/FileProcessing.c ./utils/Constants.c -I.
