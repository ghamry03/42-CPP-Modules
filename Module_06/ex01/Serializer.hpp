#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct Data {
    int         id;
    std::string name;
}   Data;

class Serializer {
    private:
                                                               Serializer(void);
                                                              ~Serializer(void);
                                            Serializer(const Serializer & copy);
                                Serializer & operator=(const Serializer & copy);


    public:
                                static  uintptr_t          serialize(Data * ptr);
                                static  Data *   deserialize(std::uintptr_t raw);
};

#endif

