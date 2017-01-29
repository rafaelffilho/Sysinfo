#include <iostream>
#include <stdlib.h>
#include <string.h>

/*
	Made by: me
	Pacman's ghost by: User
	TODO:
	Resolution
	CPU cat /proc/cpuinfo | grep "model name" | awk 'getline' | awk 'getline' | cut -c 14-
*/

using namespace std;

int main (int argc, char **argv) {

	auto pac1 = "\033[1;32m    ▄██████▄";
	auto pac2 = "\033[1;32m  ▄\033[1;37m█▀█\033[1;32m██\033[1;37m█▀█\033[1;32m██▄";
	auto pac3 = "\033[1;32m  █\033[1;37m▄▄█\033[1;32m██\033[1;37m▄▄█\033[1;32m███";
	auto pac4 = "\033[1;32m  ████████████";
	auto pac5 = "\033[1;32m  ██▀██▀▀██▀██";
 	auto pac6 = "\033[1;32m  ▀   ▀  ▀   ▀";


	int packages;
	int sharedMem;
	int usedMem;
	int totalMem;
	char uptime[56];
	char desktop[56];
	char kernel[56];
	char os[56];
	char user[56];
	char host[56];
	char cpu[56];
	auto blue = "\033[0m\033[1;34m";
	auto white = "\033[0m\033[1;37m";

	FILE *fp;
	fp = popen("pacman -Qq | wc -l", "r"); // Packages
	fscanf(fp, "%d", &packages);
	fp = popen("free -m | grep Mem | awk '{print $3}'", "r"); // Used Memory
	fscanf(fp, "%d", &usedMem);
	fp = popen("free -m | grep Mem | awk '{print $5}'", "r"); // Shared Memory
	fscanf(fp, "%d", &sharedMem);
	fp = popen("free -m | grep Mem | awk '{print $2}'", "r"); // Total Memory
	fscanf(fp, "%d", &totalMem);
	fp = popen("uptime -p | cut -b 4-", "r"); // Uptime
	fgets(uptime, 56, fp);
	uptime[strlen(uptime) - 1] = '\0';
	fp = popen("env | grep DESKTOP_SESSION= | cut -b 17-", "r"); // Desktop Session
	fgets(desktop, 56, fp);
	desktop[strlen(desktop) - 1] = '\0';
	fp = popen("uname -rm", "r"); // Kernel Version
	fgets(kernel, 56, fp);
	kernel[strlen(kernel) - 1] = '\0';
	fp = popen("cat /etc/os-release | grep PRETTY_NAME | cut -c 14- | rev | cut -c 2- | rev", "r"); // Distro Name
	fgets(os, 56, fp);
	os[strlen(os) - 1] = '\0';
	fp = popen("echo $USER", "r"); // User
	fgets(user, 56, fp);
	user[strlen(user) - 1] = '\0';
	fp = popen("hostname", "r"); // Hostname
	fgets(host, 56, fp);
	host[strlen(host) - 1] = '\0';
	fp = popen("cat /proc/cpuinfo | grep \"model name\" | awk 'getline' | awk 'getline' | cut -c 14-", "r"); // CPU
	fgets(cpu, 56, fp);
	cpu[strlen(cpu) - 1] = '\0';
	pclose(fp);


	cout << blue << "\t\t" << user << white << "@" << blue << host << endl;
	cout << "\t\t----------------" << endl;
	cout << pac1 << blue << "\tOS: " << white << os << endl;
	cout << pac2 << blue << "\tKernel: " << white << kernel << endl;
	cout << pac3 << blue << "\tUptime: " << white << uptime << endl;
	cout << pac4 << blue << "\tPackages: " << white << packages << endl;
	cout << pac5 << blue << "\tDesktop: " << white << desktop << endl;
	cout << pac6 << blue << "\tCPU: " << white << cpu << endl;
	cout << "\t" << blue << "\tRAM: " << white << sharedMem + usedMem << "MB / " << totalMem << "MB" << endl;

	return 0;
}
