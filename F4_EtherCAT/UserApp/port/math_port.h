/*
 * math_port.h
 *
 *  Created on: Jul 19, 2022
 *      Author: x9355
 */

#ifndef PORT_MATH_PORT_H_
#define PORT_MATH_PORT_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "stm32f4xx.h"

#include "arm_math.h"
#include "stdint.h"

#ifdef __cplusplus
};
#endif

//:libarm_cortexM4lf_math.a

#define Port_SinF					arm_sin_f32
#define Port_CosF					arm_cos_f32
#define Port_TanF					MathPort::TanF

#define Port_Park					arm_park_f32
#define Port_Inv_Park				arm_inv_park_f32
#define Port_Clarke					arm_clarke_f32
#define Port_SQRT					arm_sqrt_f32
#define Port_ABSF					arm_abs_f32
#define Port_iir					arm_sqrt_f32
#define Port_VecMult				arm_mult_f32
#define Port_VecScale				arm_scale_f32
#define Port_VecAdd					arm_add_f32
#define Port_VecSub					arm_sub_f32
#define Port_MatAdd					arm_mat_add_f32
#define Port_MatSub					arm_mat_sub_f32
#define Port_MatMult				arm_mat_mult_f32
#define Port_Mat					arm_matrix_instance_f32
#define Port_MatTranspose			arm_mat_trans_f32
#define Port_MatInv					arm_mat_inverse_f32

#define Port_CmplxAdd				MathPort::CmplxAdd
#define Port_CmplxSub				MathPort::CmplxSub

#define Port_CmplxMag				arm_cmplx_mag_f32
#define Port_CmplxDotProd			arm_cmplx_dot_prod_f32
#define Port_CmplxMultReal			arm_cmplx_mult_real_f32
#define Port_CmplxMultCmplx			arm_cmplx_mult_cmplx_f32
#define Port_CmplxMagSquared		arm_cmplx_mag_squared_f32
#define Port_CmplxConj				arm_cmplx_conj_f32
#define Port_CmplxScaleCmplx		MathPort::CmplxScaleCmplx
#define Port_Round(x)				(int32_t)(x+MathPort::Sgn(x)*0.5f)

#define min(a,b) ((b)<(a) ? (b) : (a))
#define max(a,b) ((b)>(a) ? (b) : (a))

/**
 * @brief Initialization function for the floating-point IIR lattice filter.
 * @param[in] S          points to an instance of the floating-point IIR lattice structure.
 * @param[in] numStages  number of stages in the filter.
 * @param[in] pkCoeffs   points to the reflection coefficient buffer.  The array is of length numStages.
 * @param[in] pvCoeffs   points to the ladder coefficient buffer.  The array is of length numStages+1.
 * @param[in] pState     points to the state buffer.  The array is of length numStages+blockSize-1.
 * @param[in] blockSize  number of samples to process.
 */

constexpr float math_PI 		= 3.14159265358979323846f;
constexpr float math_PI_by_2 	= 1.57079632679489661923f;
constexpr float math_PI_3_by_2 	= 4.71238898038468985769f;
constexpr float math_2PI 		= 6.28318530717958647692f;

constexpr float one_by_sqrt3 	= 0.57735026919f;
constexpr float two_by_sqrt3 	= 1.15470053838f;
constexpr float sqrt3_by_2 		= 0.86602540378f;
constexpr float sqrt3_by_3 		= 0.57735026918f;

namespace MathPort
{
	class Complex
	{
		public:
			Complex();
			~Complex();
			void SetVal(float32_t real, float32_t imag);
			inline float32_t Real()	{return ptr_[0];}
			inline float32_t Imag()	{return ptr_[1];}

			float32_t* ptr_;
	};

	class Matrix
	{
		public:
			Matrix(uint32_t numRows,uint32_t numCols)
			:numRows_(numRows),numCols_(numCols),numEle_(numRows*numCols)
			{
				ptr_ = new float32_t [numEle_];
				memset(ptr_,0,sizeof(float32_t [numEle_]));
				portInstance_.numRows 	=	numRows_;
				portInstance_.numCols 	=	numCols_;
				portInstance_.pData 	=	ptr_;
			}
			~Matrix(){
				delete [] ptr_;
			}
			void SetElems(float32_t *pData)
			{
				memcpy(ptr_,pData,numEle_*sizeof(float32_t));
			}
			float GetElem(uint32_t row, uint32_t col)
			{
				return ptr_[row*numCols_+col];
			}
			void SetElem(uint32_t row, uint32_t col, float32_t elem)
			{
				ptr_[row*numCols_+col] = elem;
			}


			float32_t 		*ptr_;
			const uint32_t 	numRows_;
			const uint32_t 	numCols_;
			const uint32_t 	numEle_;
			Port_Mat 		portInstance_;
	};


	int8_t Sgn(float32_t x);
	float32_t CircSubs(float32_t x1,float32_t x2);

	float32_t Factorial(uint32_t n);
	float32_t BnmCoef(uint32_t n, uint32_t k);//Binomial coefficient
	void Bnm2Ployn(float32_t a, float32_t b, uint32_t n,float32_t *pCoef);
	void PloynMulti(float32_t *pCoef1, float32_t *pCoef2, uint32_t n,uint32_t m, float32_t *pCoefRes);
	void CircleNumCalc(float32_t angleThis, float32_t angleLast,float32_t &circNum);

	void PolyCmplx(Complex roots[], uint32_t rootNbr, float32_t coef[]);

	inline float SinF(float x)	{return arm_sin_f32(x);}
	inline float CosF(float x)	{return arm_cos_f32(x);}
	inline float TanF(float x)	{return arm_sin_f32(x)/arm_cos_f32(x);}

	void CmplxAdd(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst);
	void CmplxSub(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst);
	void CmplxScaleCmplx(float32_t* pSrcA,float32_t* pSrcB, float32_t* pDst);
	void RealScaleCmplx(float32_t* pSrcReal,float32_t* pSrcCmplx, float32_t* pDstCmplx);
	void Cmplx2MagPhase(MathPort::Complex &Frd, float32_t *pMag, float32_t *pPhase);


}

#endif /* PORT_MATH_PORT_H_ */
