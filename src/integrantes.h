#ifndef INTEGRANTES_H
#define INTEGRANTES_H
#include<string>

class miembros {
private:
    int id;
    int id_boss;
    int edad;

    std::string name;
    std::string last_name;

    char genero;

    bool in_jail;
    bool was_boss;
    bool is_boss;
    bool is_dead;

public:
    miembros()
        : id(0), id_boss(-1), edad(0), name(""), last_name(""),
          genero('H'), in_jail(false), was_boss(false), is_boss(false), is_dead(false) {}

    miembros(int id, std::string name, std::string last_name, char genero,
             int edad, int id_boss, bool is_dead, bool in_jail, bool was_boss, bool is_boss)
        : id(id), id_boss(id_boss), edad(edad), name(name), last_name(last_name),
          genero(genero), in_jail(in_jail), was_boss(was_boss), is_boss(is_boss), is_dead(is_dead) {}
 
    int getId() const { return id; }
    int getIdBoss() const { return id_boss; }
    int getEdad() const { return edad; }
	std::string getName() const { return name; }
	std::string getLastName() const { return last_name; }
    char getGenero() const { return genero; }
    bool getInJail() const { return in_jail; }
    bool getWasBoss() const { return was_boss; }
    bool getIsBoss() const { return is_boss; }
    bool getIsDead() const { return is_dead; }

    void setEdad(int nuevaEdad) { edad = nuevaEdad; }
    void setName(const std::string& nuevoNombre) { name = nuevoNombre; }
    void setLastName(const std::string& nuevoApellido) { last_name = nuevoApellido; }
    void setGenero(char nuevoGenero) { genero = nuevoGenero; }
    void setInJail(bool estado) { in_jail = estado; }
    void setWasBoss(bool estado) { was_boss = estado; }
    void setIsBoss(bool estado) { is_boss = estado; }
    void setIsDead(bool estado) { is_dead = estado; }
};

#endif