#ifndef MISC_HPP
#define MISC_HPP

#include "command.hpp"
#include "object.hpp"

#include <unordered_set>
#include <unordered_map>

class Misc : public Object {
public:
    Misc(std::string input){ name = input;};
	virtual ~Misc();
 	std::unordered_set<Misc *> get_miscs();
	void add_misc(Misc *misc);
	void remove_misc(Misc *misc);
    std::string name;
	virtual bool handle(Command command);
    
    virtual std::string get_name(){return name;};
    virtual std::string get_descr(){return "How can I possibly do that?";};

private:
	std::unordered_set<Misc *> miscs;


};

#endif
