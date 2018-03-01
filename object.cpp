#include "object.hpp"

Object::~Object() {
}
std::string Object::perform_action(Parse parse) {
	return "action could not be performed";
}
// std::string Object::perform_action(Parse parse) {
// 	if (act2fn.find(parse.get_action()) != act2fn.end()) {
// 		return act2fn[parse.get_action()](parse);
// 	}
// 	return "Action cannot be completed";
// }
