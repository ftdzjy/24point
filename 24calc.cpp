/*
@desc:
 ��������20180925��C/C++����������
	�����24����Ϸ�����˿���������1-9�������ƣ�Ȼ���õ�����4���ƣ��������⽫���ĸ��ƽ���
	/*+-��ϣ�������ϵõ�24����Ӯ�ˡ�
	����������4���Ƶ�ֵ�����磬
	1 2 3 4
	����������ܹ��õ�24��Ϊtrue������false������������1*2*3*4��
	true
 ˼·��
	�����п�����ϵĽ������������õݹ飬����
	��i������ʣ��������Ͻ������/*+-����ϣ������������顣
	���磬��(1234)����Ͻ������1(/*-+)(234),2(/*-+)(134),3(/*-+)(214),4(/*-+)(231)�������������1(/*-+)(234)��������(234)
			(234)���е���2(/*-+)(34),3(/*-+)(24),4(/*-+)(23)����˷ֱ����ѡ����Ϊ2,3,4ʱʣ������Ͻ����Ȼ�����/*-+
			��(34),(24),(23)���������Դ����ƣ�
	��˹����ǣ��ȴ���������ѡ��һ����Ȼ��ʣ��Ľ�������Ͻ����Ȼ��ѡ������ý��(/*+-)����
				����������ֻ��һ��Ԫ�أ�ֱ�ӷ��ظ�Ԫ��ֵ���ɡ�
@update:
 date			author			desc
 2018/09/25		zjy				done
*/
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

#define __DEBUG__


#ifdef __DEBUG__
int calc(vector<char> nums, vector<float> &result, vector<string> &pro){
#else
int calc(vector<char> nums, vector<float> &result){
#endif
	int i,j,k;
	float tmpf;
#ifdef __DEBUG__
	char cstr[108] = {0};
	string tmpstr;
#endif

	if(nums.size() == 1){
		result.push_back(nums[0]);
#ifdef __DEBUG__
		sprintf(cstr,"%d",nums[0]);
		pro.push_back(cstr);
#endif
		return 0;
	}

	for(i = 0; i < nums.size(); i++){
		vector<char> tmps;
		vector<float> tmpre;
#ifdef __DEBUG__
		vector<string> tmpstrs;
#endif
		for(j = 0; j < nums.size(); j++){
			if(i != j)
				tmps.push_back(nums[j]);
		}
#ifdef __DEBUG__
		calc(tmps,tmpre,tmpstrs);
#else
		calc(tmps,tmpre);
#endif
		for(j = 0; j < 4; j++){			
			switch(j){
			case 0:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] + tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d + ",nums[i]);
					tmpstr = cstr + tmpstrs[k];
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 1:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] - tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d - ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 2:
				for(k = 0;k < tmpre.size();k++){
					tmpf = nums[i] * tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d * ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			case 3:
				for(k = 0;k < tmpre.size();k++){
					if(tmpre[k] == 0)
						continue;
					tmpf = nums[i] / tmpre[k];
					result.push_back(tmpf);
#ifdef __DEBUG__
					//debug
					sprintf(cstr,"%d / ",nums[i]);
					tmpstr = tmpstrs[k];
					if(tmpstr.length() > 1)
						tmpstr = "(" + tmpstr + ")";
					tmpstr = cstr + tmpstr;
					pro.push_back(tmpstr);
#endif
				}
				break;
			}
		}
	}
	return 0;
}

int main(){
	vector<char> nums;
	vector<float> result;
	vector<string> pro;
	int flag = 0;

	nums.push_back(1);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(4);
#ifdef __DEBUG__
	calc(nums,result,pro);
#else
	calc(nums,result);
#endif

	for(int i = 0;i < result.size(); i++){
		if(fabs(result[i]- 24) < 0.1 && result[i] > 0){
			flag = 1;
#ifdef __DEBUG__
			cout<<"true:"<<result[i]<<" "<<pro[i]<<endl;
#else
			cout<<"true"<<endl;
			break;
#endif
		}
	}
	if(i == result.size() && flag == 0)
		cout<<"false"<<endl;

	return 0;
}