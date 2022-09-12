#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//
 Transaction::Transaction( std::string ticker_symbol,  unsigned int day_date,  
        unsigned int month_date,  unsigned year_date, 
        bool buy_sell_trans,  unsigned int number_shares,  
        double trans_amount ){
    this->symbol = ticker_symbol;
    this->day = day_date;
    this->month = month_date;
    this->year = year_date;
    if(buy_sell_trans){
      this->trans_type = "Buy";
    } else {
      this->trans_type = "Sell";
    }
    this->shares = number_shares;
    this->amount = trans_amount;
    this->trans_id = assigned_trans_id;
    this->p_next = nullptr;
    assigned_trans_id++;
    this->acb = 0;
    this->acb_per_share = 0;
    this->share_balance = 0;
    this->cgl = 0;
        }

// Destructor
// TASK 1
//
Transaction::~Transaction(){

}

// Overloaded < operator.
// TASK 2
//
bool Transaction::operator<( Transaction const &other ){
  if(this->year < other.get_year()){
          return 1;
    } else if(this->year == other.get_year()){    
      if(this->month < other.get_month()){
        return 1; 
        } else if (this->month == other.get_month()){
            if(this->day < other.get_day()){
              return 1;
            } else{
              return 0;
            }
        } else {
          return 0;
        }
    } else {
      return 0;
  }
}
// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//
History::History(){
  this->p_head = nullptr;
}

// Destructor
// TASK 3
//
History::~History(){
  Transaction * p_find {p_head};
  while ( p_find != nullptr && p_head != nullptr ){
      p_find = p_find->get_next();
      delete p_head;
      p_head = p_find;
    }
    p_find = nullptr;
}



// read_history(...): Read the transaction history from file.
// TASK 4
//
void History::read_history(){
  ece150::open_file();

  while(ece150::next_trans_entry()){
    std::string symbol = ece150::get_trans_symbol();
    unsigned int day = ece150::get_trans_day();
    unsigned int month = ece150::get_trans_month();
    unsigned int year = ece150::get_trans_year();
    unsigned int shares = ece150::get_trans_shares();
    double amount = ece150::get_trans_amount();
    bool trans_type = ece150::get_trans_type();
    Transaction *NewTransaction{new Transaction{symbol, day, month, year, trans_type, shares, amount }};
    History::insert(NewTransaction);
  }
  ece150::close_file();
 }

// insert(...): Insert transaction into linked list.
// TASK 5
//// I attended the session on Wednesday, Nov. 17th, and this structure is provided by David Lau
void History::insert(Transaction *p_new_trans){
  
  if (p_head == nullptr){
    p_head = p_new_trans;
  } else {
    Transaction *p_find{p_head};
    while (p_find -> get_next() != nullptr)
    {
      p_find = p_find->get_next();
      
    }
    p_find->set_next(p_new_trans);  
  }
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
// I Watched the session on Friday, David Lau provide the structure
void History::sort_by_date(){
  Transaction *p_front{nullptr};
  Transaction *p_new_head{nullptr};
  while(p_head != nullptr){
    p_front = p_head;
    p_head = p_head->get_next();
    p_front->set_next(nullptr);
    if (p_new_head == nullptr){
      p_new_head = p_front;
      p_front = nullptr;
    } else {
      if( *p_front < *p_new_head){
        p_front->set_next(p_new_head);
        p_new_head = p_front;
        p_front=nullptr;
      } else {
        Transaction *p_traverse{p_new_head};
        while (p_traverse->get_next() != nullptr && *(p_traverse->get_next()) < *p_front){
          p_traverse=p_traverse->get_next();
        }
        p_front->set_next(p_traverse->get_next());
        p_traverse->set_next(p_front);
        p_front = nullptr;
        p_traverse = nullptr;
      }
    }
  }    
  p_head = p_new_head;
  p_new_head=nullptr;
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl(){
  Transaction *p_new_head{nullptr};
  p_new_head = p_head;
  double acb = 0.0;
  unsigned int sharebalance = 0;
  double acbpershare = 0;
  while (p_new_head != nullptr){
      double cgl = p_new_head->get_amount() - (p_new_head->get_shares()*acbpershare);
      if (p_new_head->get_trans_type()){
        acb += p_new_head->get_amount();
        sharebalance += p_new_head->get_shares();
        acbpershare = acb/sharebalance;
      } else { 
        acb -= p_new_head->get_shares() * acbpershare;
        sharebalance -= p_new_head->get_shares();
        p_new_head->set_cgl(cgl);
      }
      p_new_head->set_acb_per_share(acbpershare);
      p_new_head->set_acb(acb);
      p_new_head->set_share_balance(sharebalance);
      p_new_head = p_new_head->get_next();
  }

}


// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8

double History::compute_cgl(unsigned int year){
  Transaction *p_new_head = p_head;
  double cgl_for_year = 0.0;
  while (p_new_head != nullptr){
    if (p_new_head->get_year() == year) {
      cgl_for_year += p_new_head->get_cgl();
    }
    p_new_head = p_new_head->get_next();
  }
  return cgl_for_year;
}


// print() Print the transaction history.
//TASK 9
//
void History::print(){
  Transaction *p_new_head = p_head;
  std::cout << "========== BEGIN TRANSACTION HISTORY ============" << std::endl;
  while (p_new_head != nullptr){
  std::cout << p_new_head->get_trans_id() << " " << p_new_head->get_symbol() << " " << p_new_head->get_day() << " " << p_new_head->get_month() << " " 
            << p_new_head->get_year() << " "; 
            if (p_new_head->get_trans_type()){
              std::cout << "Buy" << " ";
            } else {
              std::cout << "Sell" << " ";
            } 
            std::cout << p_new_head->get_shares() << " " << p_new_head->get_amount() << " " << p_new_head->get_acb() << " " << p_new_head->get_share_balance()
            << " " << p_new_head->get_acb_per_share() << " " << p_new_head->get_cgl() << std::endl;
            p_new_head = p_new_head -> get_next();
  }
  std::cout << "========== END TRANSACTION HISTORY ============" << std::endl;
}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }
