/* Copyright © 2001-2014, Canal TP and/or its affiliates. All rights reserved.

This file is part of Navitia,
    the software to build cool stuff with public transport.

Hope you'll enjoy and contribute to this project,
    powered by Canal TP (www.canaltp.fr).
Help us simplify mobility and open public transport:
    a non ending quest to the responsive locomotion way of traveling!

LICENCE: This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

Stay tuned using
twitter @navitia
IRC #navitia on freenode
https://groups.google.com/d/forum/navitia
www.navitia.io
*/
#pragma once

#include "type/pb_converter.h"
#include "routing/routing.h"
#include "routing/get_stop_times.h"
#include "routing/raptor.h"

namespace navitia {
namespace timetables {

typedef std::vector<DateTime> vector_datetime;
typedef std::vector<routing::datetime_stop_time> vector_dt_st;

enum class datetime_type {
    first,
    last
};

void departure_board(PbCreator& pb_creator,
                     const std::string &filter,
                     const boost::optional<const std::string> calendar_id,
                     const std::vector<std::string>& forbidden_uris,
                     const boost::posix_time::ptime datetime,
                     const uint32_t duration,
                     const uint32_t depth,
                     const int count,
                     const int start_page,
                     const type::RTLevel rt_level,
                     const size_t items_per_route_point);

bool between_opening_and_closing(const time_duration& me,
                                 const time_duration& opening,
                                 const time_duration& closing);

time_duration length_of_time(const time_duration& duration_1,
                             const time_duration& duration_2);

bool line_closed (const time_duration& duration,
                  const time_duration& opening,
                  const time_duration& closing,
                  const boost::posix_time::ptime& date );

DateTime first_or_last_request_datetime(const datetime_type type,
                                        const routing::datetime_stop_time& first_stop_time,
                                        const int opening_time);
/**
 * @brief Return Opening/Closing datetime.
 */
boost::optional<routing::datetime_stop_time>
get_one_stop_time(const datetime_type type,
                  const routing::datetime_stop_time& first_stop_time,
                  const boost::posix_time::time_duration& opening_time,
                  const std::vector<routing::JppIdx>& journey_pattern_points,
                  const DateTime max_datetime,
                  const type::Data& data,
                  const type::RTLevel rt_level,
                  const size_t utc_offset);

} // namespace timetable
} // namespace navitia
