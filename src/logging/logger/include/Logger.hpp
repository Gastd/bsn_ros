#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <iostream>
#include <chrono>

#include "ros/ros.h"
#include <ros/package.h>

#include "messages/Status.h"
#include "messages/Event.h"
#include "messages/Info.h"
#include "messages/ReconfigurationCommand.h"

class Logger {

	public:
    	Logger(int &argc, char **argv, std::string);
    	virtual ~Logger();

		void setUp();
		void run();

    private:
      	Logger(const Logger &);
    	Logger &operator=(const Logger &);

		int64_t now() const;

  	public:
	  	void receiveReconfigurationCommand(const messages::ReconfigurationCommand::ConstPtr& /*msg*/);
	  	void receiveStatus(const messages::Status::ConstPtr& /*msg*/);
	  	void receiveEvent(const messages::Event::ConstPtr& /*msg*/);
	  	void receiveInfo(const messages::Info::ConstPtr& /*msg*/);

  	private:
		std::fstream fp;
		std::string filepath;
		int32_t logical_clock;
		int64_t time_ref;

		ros::Publisher reconfig_logger2effector_pub, status_logger2manager_pub, event_logger2manager_pub;
		ros::Publisher info_logger2repository_pub;

};

#endif 