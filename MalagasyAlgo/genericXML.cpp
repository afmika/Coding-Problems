#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, string rgx) {
	vector<string> results;
	regex reg(rgx, regex_constants::ECMAScript | regex_constants::icase );
	sregex_token_iterator it = sregex_token_iterator(str.begin(), str.end(), reg, -1);
	sregex_token_iterator end;

	while ( it != end ) {
		results.push_back( it->str() );
		++it;
	}
	return results;
}

struct Node {
	string value;
	vector<string> params;
	
	string xml_open () {
		string str = "<" + value;
		for (string param : params)
			str += " " + param + "=''";
		str += ">";
		return str;
	}
	
	string xml_close () {
		return "</" + value + ">";
	}
};

void dfs_read(string &xml, unordered_map<string, vector<Node *>> &m, string current) {
	vector<Node *> childs = m[current];
	for (auto child : childs) {
		xml += child->xml_open();
		dfs_read(xml, m, child->value);
		xml += child->xml_close();
	}
}

string genericXML(vector<string> specifications) {
	string xml = "<?xml version='1.0' encoding='UTF-8'?>";
	unordered_map<string, vector<Node *>> m;
	for (string spec : specifications) {
		vector<string> input = split(spec, "/");
		string curr = input[0];
		string parent = input[1];
		vector<string> params;
		if (input.size() > 2) {
			params = split(input[2], ",");
		}
			
		Node *node = new Node;
		node->value = curr;
		node->params = params;
		// - ==> root
		if (m.find(parent) == m.end())
			m[parent] = vector<Node *>();
		m[parent].push_back(node);
	}
	dfs_read(xml, m, "-");
	return xml;
}


int main () {
	vector<string> specs = {	
		"root/-/link,nb_elements", 
		 "vehicle/root/type,motor", 
		 "furniture/root/type,material", 
		 "car/vehicle/traction,engine,wheel", 
		 "dining_table/table/nb_place", 
		 "table/furniture/"
	};
	cout << genericXML(specs);
	return 0;
}
