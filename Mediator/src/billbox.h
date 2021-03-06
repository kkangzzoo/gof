/*
 * billbox.h
 *
 *  Created on: 2018. 1. 12.
 *      Author: daum
 */


#ifndef BILLBOX_H_
#define BILLBOX_H_

class Mediator;

class BillBox {
#define MAX_BILL_CNT 100

#define BILL_ACCEPT_MODE 1
#define BILL_REJECT_MODE 0

public:
	BillBox();
	void SetMediator(Mediator* pMediator);

	void InsertBill(int wantedCupCon=1);
	void RejectBill();
	void TakeOutBill(int takeOutCnt);
	void SetBillBoxMode(int mode);

protected:
	bool IsValid();

private:
	Mediator* pMediator_;
	int billCnt_;
	int mode_;
};



#endif /* BILLBOX_H_ */
