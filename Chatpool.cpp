#include "chatpool.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int chatpool::checkmap(string receiver, string nickname) {
	int v = this->chatpool_vect.size();
	int counter = 0;

	if (!this->chatpool_vect.empty()) {
		for (auto& u : this->chatpool_vect) {
	
				if (u.begin()->second == receiver + "_" + nickname || u.begin()->second == nickname + "_" + receiver) {
				   
                    return counter;
				}
            counter++;
			}
		}
	return -1;
	}

void chatpool::showmap(string receiver, string nickname) {
    int ind(0);
	for (auto& u : this->chatpool_vect) {

        if (u.begin()->second == receiver + "_" + nickname || u.begin()->second == nickname + "_" + receiver) {

            for (map<int, string>::iterator it = u.begin(); it != u.end(); ++it)
            {
                cout << it->second << endl;
                ind++;
            }
        }
	}
    if (ind == 0) { cout << "You did not chat with " << receiver << " yet! Start a conversation!" << endl; }
}

void chatpool::sendmessage(string receiver, string nickname, string message) {
    string complete_message = "from " + nickname + ": " + message;
    if (receiver == "all") {
        for (auto& u : this->chatpool_vect) {
            int x = u.size();
            u.insert({ x+1, complete_message });
            break;
        }
    }

  
    int y = this->checkmap(receiver, nickname);
    if (y == -1) {

        map <int, string> mapname;
        string ident = receiver + "_" + nickname;
        mapname.insert({ 0,ident });
        mapname.insert({ 1, complete_message });
        this->chatpool_vect.push_back(mapname);
        
    }
    else if (y > -1) {
        int size_map = this->chatpool_vect[y].size();
        this->chatpool_vect[y].insert({ size_map +1, complete_message });
    }
}