#include "meetup.h"

namespace meetup {

    scheduler::scheduler(boost::gregorian::greg_month month, int year): m_month(month),
    m_year(year) {}

    boost::gregorian::date scheduler::find_date(int boost_day_of_week, week_type week) const {
        int start_day = 1;
        int end_day = 31;

        switch (week) {
            case week_type::first: start_day = 1; end_day = 7; break;
            case week_type::second: start_day = 8; end_day = 14; break;
            case week_type::third: start_day = 15; end_day = 21; break;
            case week_type::fourth: start_day = 22; end_day = 28; break;
            case week_type::teenth: start_day = 13; end_day = 19; break;
            case week_type::last:
            // Boost calcula el último día del mes
            end_day = boost::gregorian::date(m_year, m_month, 1).end_of_month().day();
            start_day = end_day - 6;
            break;
        }

        // Barrido acotado por el rango físico
        for (int d = start_day; d <= end_day; ++d) {
            boost::gregorian::date current_date(m_year, m_month, d);
            if (current_date.day_of_week() == boost_day_of_week) {
                return current_date;
            }
        }

        return boost::gregorian::date(); // Salvaguarda simbólica
    }

    // Teenth
    boost::gregorian::date scheduler::monteenth() const {
        return find_date(boost::gregorian::Monday, week_type::teenth);
    }
    boost::gregorian::date scheduler::tuesteenth() const {
        return find_date(boost::gregorian::Tuesday, week_type::teenth);
    }
    boost::gregorian::date scheduler::wednesteenth() const {
        return find_date(boost::gregorian::Wednesday, week_type::teenth);
    }
    boost::gregorian::date scheduler::thursteenth() const {
        return find_date(boost::gregorian::Thursday, week_type::teenth);
    }
    boost::gregorian::date scheduler::friteenth() const {
        return find_date(boost::gregorian::Friday, week_type::teenth);
    }
    boost::gregorian::date scheduler::saturteenth() const {
        return find_date(boost::gregorian::Saturday, week_type::teenth);
    }
    boost::gregorian::date scheduler::sunteenth() const {
        return find_date(boost::gregorian::Sunday, week_type::teenth);
    }

    // First
    boost::gregorian::date scheduler::first_monday() const {
        return find_date(boost::gregorian::Monday, week_type::first);
    }
    boost::gregorian::date scheduler::first_tuesday() const {
        return find_date(boost::gregorian::Tuesday, week_type::first);
    }
    boost::gregorian::date scheduler::first_wednesday() const {
        return find_date(boost::gregorian::Wednesday, week_type::first);
    }
    boost::gregorian::date scheduler::first_thursday() const {
        return find_date(boost::gregorian::Thursday, week_type::first);
    }
    boost::gregorian::date scheduler::first_friday() const {
        return find_date(boost::gregorian::Friday, week_type::first);
    }
    boost::gregorian::date scheduler::first_saturday() const {
        return find_date(boost::gregorian::Saturday, week_type::first);
    }
    boost::gregorian::date scheduler::first_sunday() const {
        return find_date(boost::gregorian::Sunday, week_type::first);
    }

    // Second
    boost::gregorian::date scheduler::second_monday() const {
        return find_date(boost::gregorian::Monday, week_type::second);
    }
    boost::gregorian::date scheduler::second_tuesday() const {
        return find_date(boost::gregorian::Tuesday, week_type::second);
    }
    boost::gregorian::date scheduler::second_wednesday() const {
        return find_date(boost::gregorian::Wednesday, week_type::second);
    }
    boost::gregorian::date scheduler::second_thursday() const {
        return find_date(boost::gregorian::Thursday, week_type::second);
    }
    boost::gregorian::date scheduler::second_friday() const {
        return find_date(boost::gregorian::Friday, week_type::second);
    }
    boost::gregorian::date scheduler::second_saturday() const {
        return find_date(boost::gregorian::Saturday, week_type::second);
    }
    boost::gregorian::date scheduler::second_sunday() const {
        return find_date(boost::gregorian::Sunday, week_type::second);
    }

    // Third
    boost::gregorian::date scheduler::third_monday() const {
        return find_date(boost::gregorian::Monday, week_type::third);
    }
    boost::gregorian::date scheduler::third_tuesday() const {
        return find_date(boost::gregorian::Tuesday, week_type::third);
    }
    boost::gregorian::date scheduler::third_wednesday() const {
        return find_date(boost::gregorian::Wednesday, week_type::third);
    }
    boost::gregorian::date scheduler::third_thursday() const {
        return find_date(boost::gregorian::Thursday, week_type::third);
    }
    boost::gregorian::date scheduler::third_friday() const {
        return find_date(boost::gregorian::Friday, week_type::third);
    }
    boost::gregorian::date scheduler::third_saturday() const {
        return find_date(boost::gregorian::Saturday, week_type::third);
    }
    boost::gregorian::date scheduler::third_sunday() const {
        return find_date(boost::gregorian::Sunday, week_type::third);
    }

    // Fourth
    boost::gregorian::date scheduler::fourth_monday() const {
        return find_date(boost::gregorian::Monday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_tuesday() const {
        return find_date(boost::gregorian::Tuesday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_wednesday() const {
        return find_date(boost::gregorian::Wednesday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_thursday() const {
        return find_date(boost::gregorian::Thursday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_friday() const {
        return find_date(boost::gregorian::Friday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_saturday() const {
        return find_date(boost::gregorian::Saturday, week_type::fourth);
    }
    boost::gregorian::date scheduler::fourth_sunday() const {
        return find_date(boost::gregorian::Sunday, week_type::fourth);
    }

    // Last
    boost::gregorian::date scheduler::last_monday() const {
        return find_date(boost::gregorian::Monday, week_type::last);
    }
    boost::gregorian::date scheduler::last_tuesday() const {
        return find_date(boost::gregorian::Tuesday, week_type::last);
    }
    boost::gregorian::date scheduler::last_wednesday() const {
        return find_date(boost::gregorian::Wednesday, week_type::last);
    }
    boost::gregorian::date scheduler::last_thursday() const {
        return find_date(boost::gregorian::Thursday, week_type::last);
    }
    boost::gregorian::date scheduler::last_friday() const {
        return find_date(boost::gregorian::Friday, week_type::last);
    }
    boost::gregorian::date scheduler::last_saturday() const {
        return find_date(boost::gregorian::Saturday, week_type::last);
    }
    boost::gregorian::date scheduler::last_sunday() const {
        return find_date(boost::gregorian::Sunday, week_type::last);
    }

}