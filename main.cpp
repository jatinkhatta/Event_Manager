#include <iostream>
#include <map>
#include <string>
using namespace std;

// Event structure
struct Event {
    string title;
    string description;
    string time;
};

// Calendar class
class Calendar {
private:
    map<string, Event> events; // map to store events with date as the key

public:
    // Add an event
    void addEvent(const string& date, const Event& event) {
        events[date] = event;
        cout << "Event added on " << date << endl;
    }

    // Remove an event
    void removeEvent(const string& date) {
        if (events.erase(date)) {
            cout << "Event removed from " << date << endl;
        } else {
            cout << "No event found on " << date << endl;
        }
    }

    // Update an event
    void updateEvent(const string& date, const Event& event) {
        if (events.find(date) != events.end()) {
            events[date] = event;
            cout << "Event updated on " << date << endl;
        } else {
            cout << "No event found on " << date << endl;
        }
    }

    // Display all events
    void displayEvents() const {
        if (events.empty()) {
            cout << "No events in the calendar." << endl;
        } else {
            for (const auto& entry : events) {
                cout << "Date: " << entry.first << "\nTitle: " << entry.second.title
                     << "\nDescription: " << entry.second.description
                     << "\nTime: " << entry.second.time << "\n" << endl;
            }
        }
    }

    // Display events for a specific date
    void displayEvent(const string& date) const {
        auto it = events.find(date);
        if (it != events.end()) {
            cout << "Date: " << it->first << "\nTitle: " << it->second.title
                 << "\nDescription: " << it->second.description
                 << "\nTime: " << it->second.time << "\n" << endl;
        } else {
            cout << "No event found on " << date << endl;
        }
    }
};

// Main function
int main() {
    Calendar calendar;
    int choice;
    string date;
    Event event;

    do {
        cout << "1. Add Event\n2. Remove Event\n3. Update Event\n4. Display All Events\n5. Display Event for a Date\n6. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To consume the newline character

        switch (choice) {
            case 1:
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter title: ";
                getline(cin, event.title);
                cout << "Enter description: ";
                getline(cin, event.description);
                cout << "Enter time (HH:MM): ";
                getline(cin, event.time);
                calendar.addEvent(date, event);
                break;

            case 2:
                cout << "Enter date (YYYY-MM-DD) to remove: ";
                getline(cin, date);
                calendar.removeEvent(date);
                break;

            case 3:
                cout << "Enter date (YYYY-MM-DD) to update: ";
                getline(cin, date);
                cout << "Enter new title: ";
                getline(cin, event.title);
                cout << "Enter new description: ";
                getline(cin, event.description);
                cout << "Enter new time (HH:MM): ";
                getline(cin, event.time);
                calendar.updateEvent(date, event);
                break;

            case 4:
                calendar.displayEvents();
                break;

            case 5:
                cout << "Enter date (YYYY-MM-DD) to display: ";
                getline(cin, date);
                calendar.displayEvent(date);
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
