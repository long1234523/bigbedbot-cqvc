#define CQAPPID "com.yaasdf.bigbedbot" //���޸�AppID������� http://d.cqp.me/Pro/����/������Ϣ
#define CQAPPINFO CQAPIVERTEXT "," CQAPPID

inline bool enabled = false;

#include "app/dbconn.h"
enum enumCQBOOL
{
    FALSE,
    TRUE
};
extern int64_t QQME;

////////////////////////////////////////////////////////////////////////////////

#include <thread>
#include <chrono>
inline void timedCommit(SQLite& db)
{
    db.transactionStart();
    while (enabled)
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1min);
        db.commit(true);
    }
    db.transactionStop();
}

////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> msg2args(const char* msg);
std::string gbk2utf8(std::string gbk);
std::string utf82gbk(std::string utf8);


////////////////////////////////////////////////////////////////////////////////
#include <random>
inline std::random_device random_rd;  // �����ڻ����������������
inline std::mt19937 random_gen(random_rd()); // �� rd() ���ֵı�׼ mersenne_twister_engine

inline int randInt(int min, int max)   // [min, max]
{
    std::uniform_int_distribution<> dis(min, max);
    return dis(random_gen);
}

inline double randReal(double min = 0.0, double max = 1.0) // [min, max)
{
    std::uniform_real_distribution<> dis(min, max);
    return dis(random_gen);
}

////////////////////////////////////////////////////////////////////////////////

std::string strip(std::string& s);
std::string stripImage(std::string& s);
std::string stripFace(std::string& s);


/*
Ⱥ��Ա��Ϣ
��**CQ_getGroupMemberInfoV2**���ص���Ϣ
ǰ8���ֽڣ���һ��Int64_t���ȣ�QQȺ�ţ�
������8���ֽڣ���һ��Int64_t���ȣ�QQ�ţ�
������2���ֽڣ���һ��short���ȣ��ǳƳ��ȣ�
�������ǳƳ��ȸ��ֽڣ��ǳ��ı���
������2���ֽڣ���һ��short���ȣ�Ⱥ��Ƭ���ȣ�
������Ⱥ��Ƭ���ȸ��ֽڣ�Ⱥ��Ƭ�ı���
������4���ֽڣ���һ��int���ȣ��Ա�0��1Ů��
������4���ֽڣ���һ��int���ȣ����䣬QQ�ﲻ��ֱ���޸����䣬�Գ�����Ϊ׼��
������2���ֽڣ���һ��short���ȣ��������ȣ�
�������������ȸ��ֽڣ������ı���
������4���ֽڣ���һ��int���ȣ���Ⱥʱ�����
������4���ֽڣ���һ��int���ȣ������ʱ�����
������2���ֽڣ���һ��short���ȣ�Ⱥ�ȼ����ȣ�
������Ⱥ�ȼ����ȸ��ֽڣ�Ⱥ�ȼ��ı���
������4���ֽڣ���һ��int���ȣ�����Ȩ�ޣ�1��Ա��2����Ա��3Ⱥ����
������4���ֽڣ���һ��int���ȣ�0����֪����ʲô�������ǲ�����¼��Ա��
������2���ֽڣ���һ��short���ȣ�ר��ͷ�γ��ȣ�
������ר��ͷ�γ��ȳ��ȸ��ֽڣ�ר��ͷ�γ����ı���
������4���ֽڣ���һ��int���ȣ�ר��ͷ�ι���ʱ�����
������4���ֽڣ���һ��int���ȣ������޸���Ƭ��1�����²�0�ǲ�����
*/

//card: 8+8+2+?+2+?
std::string getCardFromGroupInfoV2(const char* base64_decoded);
std::string getCard(int64_t group, int64_t qq);

// 1��Ա��2����Ա��3Ⱥ��
int getPermissionFromGroupInfoV2(const char* base64_decoded);

inline std::string CQ_At(int64_t qq)
{
    std::stringstream ss;
    ss << "[CQ:at,qq=" << qq << "]";
    return ss.str();
}

////////////////////////////////////////////////////////////////////////////////

inline const std::string EMOJI_HORSE    = "[CQ:emoji,id=128052]";
inline const std::string EMOJI_HAMMER   = "[CQ:emoji,id=128296]";
inline const std::string EMOJI_DOWN     = "[CQ:emoji,id=11015]";
inline const std::string EMOJI_NONE     = "[CQ:emoji,id=127514]";
inline const std::string EMOJI_HORN     = "[CQ:emoji,id=128227]";