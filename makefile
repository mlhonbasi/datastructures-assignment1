All: Derle Bagla Calistir

Derle:
	g++ -I "./include" -c ./src/SatirDugum.cpp -o ./lib/SatirDugum.o
	g++ -I "./include" -c ./src/Konsol.cpp -o ./lib/Konsol.o
	g++ -I "./include" -c ./src/OkuEkle.cpp -o ./lib/OkuEkle.o
	g++ -I "./include" -c ./src/YoneticiDugum.cpp -o ./lib/YoneticiDugum.o
	g++ -I "./include" -c ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -I "./include" -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

Bagla:
	g++ ./lib/SatirDugum.o ./lib/Konsol.o ./lib/OkuEkle.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/YoneticiDugum.o ./lib/main.o -o ./bin/program

Calistir:
	./bin/program.exe
