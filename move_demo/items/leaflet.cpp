#include "leaflet.hpp"

#include "../../gameio.hpp"

Leaflet::Leaflet() {

}

std::string Leaflet::get_name() {
	return name;
}

std::string Leaflet::get_descr() {
	return description;
}

bool Leaflet::handle(Command c) {
	return Item::handle(c);
}
