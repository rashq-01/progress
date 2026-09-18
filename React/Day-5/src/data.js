// src/data.js
export const userData = {
  id: 1,
  name: "Alex Johnson",
  username: "@alexj",
  bio: "Frontend Developer | React Enthusiast | Coffee Lover ☕",
  location: "San Francisco, CA",
  joinDate: "January 2023",
  profileImage: "https://i.pravatar.cc/150?img=1",
  coverImage: "https://picsum.photos/800/200?random=1",
  isVerified: true,
  isOnline: true
};

export const stats = {
  posts: 156,
  followers: 2458,
  following: 342,
  likes: 12560
};

export const posts = [
  {
    id: 1,
    title: "Just learned React Hooks!",
    content: "useState and useEffect are game changers!",
    likes: 42,
    comments: 8,
    shares: 3,
    timestamp: "2 hours ago",
    tags: ["react", "webdev", "javascript"]
  },
  {
    id: 2,
    title: "My new project",
    content: "Working on an amazing dashboard with React and Tailwind CSS",
    likes: 128,
    comments: 24,
    shares: 12,
    timestamp: "1 day ago",
    tags: ["react", "tailwind", "project"]
  },
  {
    id: 3,
    title: "React Conference 2024",
    content: "Amazing talks and met so many developers!",
    likes: 256,
    comments: 42,
    shares: 18,
    timestamp: "3 days ago",
    tags: ["conference", "react", "networking"]
  }
];

export const friends = [
  { id: 1, name: "Sarah Miller", mutual: 24, avatar: "https://i.pravatar.cc/150?img=5" },
  { id: 2, name: "Mike Chen", mutual: 18, avatar: "https://i.pravatar.cc/150?img=6" },
  { id: 3, name: "Emma Wilson", mutual: 32, avatar: "https://i.pravatar.cc/150?img=7" },
  { id: 4, name: "David Park", mutual: 15, avatar: "https://i.pravatar.cc/150?img=8" }
];