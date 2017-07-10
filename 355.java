import java.util.*;



public class Twitter {



    public Hashtable <Integer, List<Integer>> followTable;

    public Hashtable <Integer, List<String>> tweets;

    public int time;



    /** Initialize your data structure here. */

    public Twitter() {

        this.followTable = new Hashtable<>();

        this.tweets = new Hashtable<>();

        this.time = Integer.MAX_VALUE;

    }

    

    /** Compose a new tweet. */

    public void postTweet(int userId, int tweetId) {

        if(!tweets.containsKey(userId)){

            List<String> list = new ArrayList<>();

            tweets.put(userId, list);

        }

        List<String> userTweet = tweets.get(userId);

        userTweet.add(time-- + "," + tweetId);

    }

    

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */

    public List<Integer> getNewsFeed(int userId) { 

        List<Integer> followList = followTable.get(userId);

        List<String> allNews = new ArrayList<>();

        

        List<String> myNews = tweets.get(userId);

        if(myNews != null)

            allNews.addAll(myNews);

        if(followList != null){

            for(Integer followId: followList){

                List<String> followNews = tweets.get(followId);

                if(followNews != null)

                    allNews.addAll(followNews);

            }

        }



        List<Integer> newsFeed = new ArrayList<>();

        Collections.sort(allNews);

        for(int i = 0; i<10 && i<allNews.size(); i++){

            String news = allNews.get(i);

            String[] reg = news.split(",");

            newsFeed.add(Integer.parseInt(reg[1]));

        }

        return newsFeed;

    }

    

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */

    public void follow(int followerId, int followeeId) {

        if(followerId == followeeId){

            return;

        }

        if(!followTable.containsKey(followerId)){

            followTable.put(followerId, new ArrayList<Integer>());

        }

        List<Integer> list = followTable.get(followerId);

        if(list.contains(followeeId)){

            return;

        }

        followTable.get(followerId).add(followeeId);

    }

    

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */

    public void unfollow(int followerId, int followeeId) {

        if(followerId == followeeId){

            return;

        }

        if(!followTable.containsKey(followerId)){

            return;

        }

        List<Integer> list = followTable.get(followerId);

        if(!list.contains(followeeId)){

            return;

        }

        list.remove((Integer)followeeId);

    }

}



/**

 * Your Twitter object will be instantiated and called as such:

 * Twitter obj = new Twitter();

 * obj.postTweet(userId,tweetId);

 * List<Integer> param_2 = obj.getNewsFeed(userId);

 * obj.follow(followerId,followeeId);

 * obj.unfollow(followerId,followeeId);

 */


