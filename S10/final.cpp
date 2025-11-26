class Pippo final {

};

// Pippo non può essere derivato
/*class Topolino : public Pippo {

};*/

class Minnie {
public:
    virtual void f(int x) final {}
};

class Clarabella : public Minnie {
public:
    // Override di un metodo final non è possibile
    // void f(int x) override {}
};

int main()
{

}
