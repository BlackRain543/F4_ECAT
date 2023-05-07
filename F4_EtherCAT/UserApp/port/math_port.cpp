/*
 * math_port.cpp
 *
 *  Created on: Aug 29, 2022
 *      Author: Chen Xu OwO
 */
#include "port/math_port.h"

int8_t MathPort::Sgn(float32_t in)
{
	int8_t res = 0;
	if(in > 0)
		res = 1;
	else if(in < 0)
		res = -1;
	return res;
}

float32_t MathPort::CircSubs(float32_t x1,float32_t x2)
{
	float32_t cirDis,cirDisAbs,cirDisRemainAbs;
	cirDis = x1 - x2;
	cirDisAbs = std::abs(cirDis);
	cirDisRemainAbs = 2*math_PI - cirDisAbs;
	if(cirDisAbs > cirDisRemainAbs)
		cirDis = -MathPort::Sgn(cirDis)*cirDisRemainAbs;
	return cirDis;
}
float32_t MathPort::Factorial(uint32_t n)// Return n!
{
	float32_t val = 1.0f;
	for(uint32_t i = 0;i < n;i++)
	{
		val *= (float32_t)(i+1);
	}
	return val;
}

float32_t MathPort::BnmCoef(uint32_t n, uint32_t k)// Return n!/(k!*(n-k)!)
{
	float32_t n_factorial,k_factorial,n_sub_k_factorial,val;
	n_factorial =		MathPort::Factorial(n);
	k_factorial =		MathPort::Factorial(k);
	n_sub_k_factorial =	MathPort::Factorial(n-k);

	val =n_factorial/(k_factorial * n_sub_k_factorial);
	return val;
}

//arm_matrix_instance_f32
void MathPort::Bnm2Ployn(float32_t a, float32_t b, uint32_t n,float32_t *pCoef)
// Change Binomial to Polynomial (a*z+b)^n ---> coef * [z^n z^(n-1) ... 1]^T
{
	for(uint32_t i = 0;i <= n;i++)
	{
		pCoef[n-i] = MathPort::BnmCoef(n,i) * pow(a,i) * pow(b,n-i);
	}
}

void MathPort::PloynMulti(float32_t *pCoef1, float32_t *pCoef2, uint32_t orderCoef1,uint32_t orderCoef2, float32_t *pCoefRes)
// Calculate Polynomials Multiply
// n = orderCoef1
// m = orderCoef2
// coef_res * [z^(n+m) z^(n+m-1) .. 1] = coef1 * [z^n z^(n-1) .. 1]^T * coef2 * [z^m z^(m-1) .. 1]^T
{
	uint32_t lenCoefResult = orderCoef1+orderCoef2+1;
	uint32_t lenCoef1 = orderCoef1+1;
	uint32_t lenCoef2 = orderCoef2+1;
	float32_t *pVecTempNM1 = new float32_t [lenCoefResult];
	float32_t *pVecTempM1 = new float32_t [lenCoef2];

	memset(pCoefRes,0,lenCoefResult * sizeof(float32_t));
	//memset(pVecTempNM1,orderResult, sizeof(float32_t));
	//memset(pVecTempM1,order2, sizeof(float32_t));
	for(uint32_t i =0; i<lenCoef1; i++)
	{
		Port_VecScale(pCoef2,pCoef1[i],pVecTempM1,lenCoef2);
		memset(pVecTempNM1,0,lenCoefResult *sizeof(float32_t));
		memcpy(&pVecTempNM1[i],pVecTempM1,lenCoef2 * sizeof(float32_t));
		Port_VecAdd(pCoefRes,pVecTempNM1,pCoefRes,lenCoefResult);
	}
	delete [] pVecTempNM1;
	delete [] pVecTempM1;
}

void MathPort::CircleNumCalc(float32_t angleThis, float32_t angleLast,float32_t &circNum)
{
	if(angleLast > math_PI_3_by_2 && angleThis < math_PI_by_2)
	{
		circNum += 1;
	}
	else if(angleLast < math_PI_by_2 && angleThis > math_PI_3_by_2)
	{
		circNum -= 1;
	}
}

MathPort::Complex::Complex()
{
	ptr_ = new float32_t [2];
	memset(ptr_,0,sizeof(float32_t) * 2);
}
MathPort::Complex::~Complex()
{
	delete [] ptr_;
}
void MathPort::Complex::SetVal(float32_t real, float32_t imag)
{
	ptr_[0] = real;
	ptr_[1] = imag;
}

void MathPort::CmplxAdd(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst)
{
	pDst[0] = pSrcA[0] + pSrcB[0];
	pDst[1] = pSrcA[1] + pSrcB[1];
}

void MathPort::CmplxSub(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst)
{
	pDst[0] = pSrcA[0] - pSrcB[0];
	pDst[1] = pSrcA[1] - pSrcB[1];
}

void MathPort::CmplxScaleCmplx(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst)
{
	float32_t B_MagSquared = 0.0f;
	Port_CmplxMagSquared(pSrcB,&B_MagSquared,1);
	float32_t B_MagSquared_inv = 1.0f/B_MagSquared;
	float32_t BConj[2];
	float32_t A_cmplxMultcmplx_BConj[2];

	Port_CmplxConj(pSrcB,BConj,1);
	Port_CmplxMultCmplx(pSrcA,BConj,A_cmplxMultcmplx_BConj,1);
	Port_CmplxMultReal(A_cmplxMultcmplx_BConj,&B_MagSquared_inv,pDst,1);
}

void MathPort::RealScaleCmplx(float32_t* pSrcReal,float32_t* pSrcCmplx, float32_t* pDstCmplx)
{
	float32_t *pSrcA =pSrcReal;
	float32_t *pSrcB =pSrcCmplx;
	float32_t B_MagSquared = 0.0f;
	float32_t B_MagSquared_inv = 0.0f;
	float32_t BConj[2];
	float32_t A_realMultcmplx_BConj[2];


	Port_CmplxMagSquared(pSrcB,&B_MagSquared,1);
	B_MagSquared_inv = 1.0f/B_MagSquared;
	Port_CmplxConj(pSrcB,BConj,1);
	Port_CmplxMultReal(BConj,pSrcA,A_realMultcmplx_BConj,1);
	Port_CmplxMultReal(A_realMultcmplx_BConj,&B_MagSquared_inv,pDstCmplx,1);
}

void MathPort::Cmplx2MagPhase(MathPort::Complex &Frd, float32_t *pMag, float32_t *pPhase)
{
	float32_t mag = 0.0f;
	float32_t phase = 0.0f;
	float32_t cosPhase = 0.0f;

	Port_CmplxMag(Frd.ptr_,&mag,1);
	cosPhase = Frd.Real()/mag;
	phase = std::acos(cosPhase);
	if(Frd.Imag() < 0.0f)
		phase = math_2PI-phase;

	*pMag = 	mag;
	*pPhase = 	phase;
}


// Refer to MATLAB poly.m
void MathPort::PolyCmplx(MathPort::Complex* roots, uint32_t n, float32_t* coef)
{
	MathPort::Complex c[n+1];
	MathPort::Complex ei_mult_cjsub1;
	c[0].SetVal(1.0f, 0.0f);
	for(uint32_t i = 0; i < n; i++)
	{
		for(int32_t j = i+1; j >= 1; j--)
		{
			Port_CmplxMultCmplx(roots[i].ptr_,c[j-1].ptr_,ei_mult_cjsub1.ptr_,1);
			Port_CmplxSub(c[j].ptr_,ei_mult_cjsub1.ptr_,c[j].ptr_);
		}
	}
	for(uint32_t i = 0; i < n+1; i++)
		coef[i] = c[i].Real();
}

