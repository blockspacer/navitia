#pragma once
#include "type/pb_converter.h"
#include "routing/routing.h"

namespace navitia { namespace timetables {
struct request_parser {
    pbnavitia::Response pb_response;
    routing::DateTime date_time;
    routing::DateTime max_datetime;
    std::vector<type::idx_t> route_points;

    request_parser(const std::string &API, const std::string &request, const std::string &change_time,
                   uint32_t duration, const type::Data & data);

    request_parser(const std::string &API, const std::string str_dt, const type::Data & data);

    routing::DateTime parse_time(const std::string str_dt, const type::Data & data);
};
}

}

