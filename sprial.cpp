#include "rclcpp/rclcpp.hpp"  
#include "geometry_msgs/msg/twist.hpp" 


class SpiralNode : public rclcpp::Node {   
public:
  SpiralNode() : Node("spiral_node") {    
    my_publisher = create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);   
    my_timer = create_wall_timer(std::chrono::milliseconds(100),    std::bind(&SpiralNode::moveTurtle,this));
  }


private:
  void moveTurtle() {
    geometry_msgs::msg::Twist msg;
    msg.linear.x = linear_vel;
    msg.angular.z = angular_vel;
    my_publisher->publish(msg);
    linear_vel+= linear_inc;
    angular_vel+= angular_inc;
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr my_publisher;
  rclcpp::TimerBase::SharedPtr my_timer;
  
  double linear_vel = 0.5;
  double angular_vel = 0.1;
  double linear_inc = 0.05;
  double angular_inc = 0.01;
};

  int main(int argc, char** argv) {
     // argc = cmd line arg
    // argv = array of cmd line args    
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<SpiralNode>());

    rclcpp::shutdown();

    return 0;
  }



